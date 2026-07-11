#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Each custom -ate ability maps Normal moves to its described type")
{
    enum Ability ability;
    enum Type type;

    PARAMETRIZE { ability = ABILITY_FIGHTING_ATE; type = TYPE_FIGHTING; }
    PARAMETRIZE { ability = ABILITY_POISON_ATE;   type = TYPE_POISON; }
    PARAMETRIZE { ability = ABILITY_GROUND_ATE;   type = TYPE_GROUND; }
    PARAMETRIZE { ability = ABILITY_ROCK_ATE;     type = TYPE_ROCK; }
    PARAMETRIZE { ability = ABILITY_BUG_ATE;      type = TYPE_BUG; }
    PARAMETRIZE { ability = ABILITY_GHOST_ATE;    type = TYPE_GHOST; }
    PARAMETRIZE { ability = ABILITY_STEEL_ATE;    type = TYPE_STEEL; }
    PARAMETRIZE { ability = ABILITY_FIRE_ATE;     type = TYPE_FIRE; }
    PARAMETRIZE { ability = ABILITY_WATER_ATE;    type = TYPE_WATER; }
    PARAMETRIZE { ability = ABILITY_GRASS_ATE;    type = TYPE_GRASS; }
    PARAMETRIZE { ability = ABILITY_PSYCHIC_ATE;  type = TYPE_PSYCHIC; }
    PARAMETRIZE { ability = ABILITY_DRAGON_ATE;   type = TYPE_DRAGON; }
    PARAMETRIZE { ability = ABILITY_DARK_ATE;     type = TYPE_DARK; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        const enum BattlerId battler = (enum BattlerId)B_POSITION_PLAYER_LEFT;

        EXPECT(GetDynamicMoveType(GetBattlerMon(battler), MOVE_SCRATCH, battler, MON_IN_BATTLE) == type);
    }
}

SINGLE_BATTLE_TEST("Fire-ate turns a Normal-type move into a Fire-type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_FIRE_ATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Fire-ate boosts affected Normal-type moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_BLAZE; }
    PARAMETRIZE { ability = ABILITY_FIRE_ATE; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, GEN_7);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.2), results[1].damage);
    }
}
