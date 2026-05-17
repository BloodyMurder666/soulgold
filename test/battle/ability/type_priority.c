#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Full HP type-priority abilities give priority to their matching type moves")
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_READY_STANCE;    move = MOVE_TACKLE; }
    PARAMETRIZE { ability = ABILITY_FIRST_STRIKE;    move = MOVE_KARATE_CHOP; }
    PARAMETRIZE { ability = ABILITY_TOXIC_REFLEX;    move = MOVE_POISON_STING; }
    PARAMETRIZE { ability = ABILITY_EARTHEN_RUSH;    move = MOVE_MUD_SLAP; }
    PARAMETRIZE { ability = ABILITY_STONE_SENTINEL;  move = MOVE_ROCK_THROW; }
    PARAMETRIZE { ability = ABILITY_SWARM_INSTINCT;  move = MOVE_BUG_BITE; }
    PARAMETRIZE { ability = ABILITY_PHANTOM_STEP;    move = MOVE_SHADOW_BALL; }
    PARAMETRIZE { ability = ABILITY_QUICK_FORGE;     move = MOVE_METAL_CLAW; }
    PARAMETRIZE { ability = ABILITY_FLAME_RUSH;      move = MOVE_EMBER; }
    PARAMETRIZE { ability = ABILITY_TIDAL_REFLEX;    move = MOVE_WATER_GUN; }
    PARAMETRIZE { ability = ABILITY_VERDANT_GALE;    move = MOVE_VINE_WHIP; }
    PARAMETRIZE { ability = ABILITY_STATIC_BURST;    move = MOVE_SHOCK_WAVE; }
    PARAMETRIZE { ability = ABILITY_THINK_AHEAD;     move = MOVE_PSYSHOCK; }
    PARAMETRIZE { ability = ABILITY_FROST_SNAP;      move = MOVE_ICE_SPINNER; }
    PARAMETRIZE { ability = ABILITY_DRACONIC_REFLEX; move = MOVE_DRAGON_CLAW; }
    PARAMETRIZE { ability = ABILITY_NIGHT_STALKER;   move = MOVE_FEINT_ATTACK; }
    PARAMETRIZE { ability = ABILITY_FAIRY_BLINK;     move = MOVE_FAIRY_WIND; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_KARATE_CHOP) == TYPE_FIGHTING);
        ASSUME(GetMoveType(MOVE_POISON_STING) == TYPE_POISON);
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_ROCK_THROW) == TYPE_ROCK);
        ASSUME(GetMoveType(MOVE_BUG_BITE) == TYPE_BUG);
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_METAL_CLAW) == TYPE_STEEL);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
        ASSUME(GetMoveType(MOVE_SHOCK_WAVE) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_PSYSHOCK) == TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_ICE_SPINNER) == TYPE_ICE);
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        ASSUME(GetMoveType(MOVE_FEINT_ATTACK) == TYPE_DARK);
        ASSUME(GetMoveType(MOVE_FAIRY_WIND) == TYPE_FAIRY);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); HP(100); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Think Ahead only grants Psychic priority at full HP")
{
    u32 hp;

    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 99; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_PSYSHOCK) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_THINK_AHEAD); HP(hp); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYSHOCK); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (hp == 100) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, player);
        }
    }
}

SINGLE_BATTLE_TEST("Think Ahead only grants priority to Psychic-type moves")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_PSYSHOCK; }
    PARAMETRIZE { move = MOVE_TACKLE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_PSYSHOCK) == TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_THINK_AHEAD); HP(100); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (move == MOVE_PSYSHOCK) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        }
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Think Ahead only grants Psychic priority at full HP (Traits)")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_PSYSHOCK) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); Innates(ABILITY_THINK_AHEAD); HP(100); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYSHOCK); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYSHOCK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}
#endif
