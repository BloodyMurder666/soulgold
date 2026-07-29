#include "global.h"
#include "event_data.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Gang Up boosts damage if the target was already damaged this turn", s16 damage)
{
    bool32 priorDamage;

    PARAMETRIZE { priorDamage = FALSE; }
    PARAMETRIZE { priorDamage = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GANG_UP); Speed(50); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            if (priorDamage)
                MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
            else
                MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
        }
    } SCENE {
        if (priorDamage)
            HP_BAR(opponentLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

DOUBLE_BATTLE_TEST("Gang Up remembers damage even if the target heals before the user's attack", s16 damage)
{
    bool32 priorDamage;

    PARAMETRIZE { priorDamage = FALSE; }
    PARAMETRIZE { priorDamage = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GANG_UP); Speed(50); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(300); MaxHP(400); Speed(75); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            if (priorDamage)
                MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
            else
                MOVE(playerRight, MOVE_CELEBRATE);
            MOVE(opponentLeft, MOVE_RECOVER);
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
        }
    } SCENE {
        if (priorDamage)
            HP_BAR(opponentLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Pendulum increases repeated move damage and resets on a different move")
{
    s16 firstDamage, repeatedDamage, resetDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PENDULUM); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &firstDamage);
        HP_BAR(opponent, captureDamage: &repeatedDamage);
        HP_BAR(opponent);
        HP_BAR(opponent, captureDamage: &resetDamage);
    } THEN {
        EXPECT_GT(repeatedDamage, firstDamage);
        EXPECT_EQ(resetDamage, firstDamage);
    }
}

SINGLE_BATTLE_TEST("Monsoon lets Water moves bypass Water Absorb during rain")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_MONSOON; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        STARTING_WEATHER(B_WEATHER_RAIN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } THEN {
        if (ability == ABILITY_MONSOON)
            EXPECT_LT(opponent->hp, opponent->maxHP);
        else
            EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}


#if MAX_MON_TRAITS > 1

SINGLE_BATTLE_TEST("Monsoon recognizes Normal moves converted to Water")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveType(MOVE_SLAM) == TYPE_NORMAL);
        ASSUME(GetMoveAccuracy(MOVE_SLAM) < 100);
        STARTING_WEATHER(B_WEATHER_RAIN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MONSOON); Innates(ABILITY_WATER_ATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLAM, player);
        HP_BAR(opponent);
    }
}
#endif

SINGLE_BATTLE_TEST("Blitz starts unarmed and boosts one damaging move after Protect")
{
    s16 unarmedDamage, boostedDamage, spentDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLITZ); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &unarmedDamage);
        HP_BAR(opponent, captureDamage: &boostedDamage);
        HP_BAR(opponent, captureDamage: &spentDamage);
    } THEN {
        EXPECT_GT(boostedDamage, unarmedDamage);
        EXPECT_EQ(spentDamage, unarmedDamage);
    }
}

SINGLE_BATTLE_TEST("Blitz keeps its charge through a non-damaging move")
{
    s16 boostedDamage, spentDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLITZ); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &boostedDamage);
        HP_BAR(opponent, captureDamage: &spentDamage);
    } THEN {
        EXPECT_GT(boostedDamage, spentDamage);
    }
}

SINGLE_BATTLE_TEST("Echo Chamber makes sound moves hit harder", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_ECHO_CHAMBER; }
    GIVEN {
        ASSUME(IsSoundMove(MOVE_ROUND));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_LT(results[1].hp, results[0].hp);
    }
}

SINGLE_BATTLE_TEST("Echo Chamber ignores non-sound moves", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_ECHO_CHAMBER; }
    GIVEN {
        ASSUME(!IsSoundMove(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(200); MaxHP(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, results[1].hp);
    }
}

SINGLE_BATTLE_TEST("Flare boosts Fire moves against burned targets", s16 damage)
{
    bool32 burned;

    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLARE); }
        OPPONENT(SPECIES_WOBBUFFET) { if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Flare ignores non-Fire moves", s16 damage)
{
    bool32 burned;

    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLARE); }
        OPPONENT(SPECIES_WOBBUFFET) { if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Splinter chips each foe damaged by its holder at turn end")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SWIFT) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPLINTER); SpAttack(100); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(96); MaxHP(96); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(160); MaxHP(160); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SWIFT); }
    } SCENE {
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_SPLINTER);
        HP_BAR(opponentLeft, damage: 6);
        ABILITY_POPUP(playerLeft, ABILITY_SPLINTER);
        HP_BAR(opponentRight, damage: 10);
    }
}

DOUBLE_BATTLE_TEST("Splinter ignores non-damaging moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPLINTER); HP(100); MaxHP(100); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL, target: opponentLeft); }
    } THEN {
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Splinter does not retaliate when its holder is damaged")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPLINTER); HP(100); MaxHP(100); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } THEN {
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_EQ(opponentRight->hp, opponentRight->maxHP);
    }
}

SINGLE_BATTLE_TEST("Cosmic Form lets direct attacks bypass type immunities", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_COSMIC_FORM; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_GEODUDE) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, 100);
        EXPECT_LT(results[1].hp, 100);
    }
}

SINGLE_BATTLE_TEST("Cosmic Form reduces super-effective direct damage taken", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_COSMIC_FORM; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_BALL); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Null Space lets direct moves hit through Protect", u16 hp)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_NULL_SPACE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SCRATCH); }
    } THEN {
        results[i].hp = opponent->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, 100);
        EXPECT_LT(results[1].hp, 100);
    }
}

SINGLE_BATTLE_TEST("Null Space halves damage through Protect", s16 damage)
{
    bool32 protect;

    PARAMETRIZE { protect = FALSE; }
    PARAMETRIZE { protect = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NULL_SPACE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            if (protect)
                MOVE(opponent, MOVE_PROTECT);
            MOVE(player, MOVE_SCRATCH);
        }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Underdog boosts damage against higher-BST targets", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_UNDERDOG; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_MEWTWO) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Underdog does not boost damage against lower-BST targets", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_UNDERDOG; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_MAGIKARP) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Horse Council boosts physical and special damage by 10 percent per living horse ally", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { ability = ABILITY_NONE; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_HORSE_COUNCIL; move = MOVE_SCRATCH; }
    PARAMETRIZE { ability = ABILITY_NONE; move = MOVE_CONFUSION; }
    PARAMETRIZE { ability = ABILITY_HORSE_COUNCIL; move = MOVE_CONFUSION; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_CONFUSION) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(200); SpAttack(200); }
        PLAYER(SPECIES_PONYTA);
        PLAYER(SPECIES_RAPIDASH_GALAR);
        PLAYER(SPECIES_PALKIA_ORIGIN);
        PLAYER(SPECIES_ARCEUS_FIRE);
        PLAYER(SPECIES_TAUROS_PALDEA_AQUA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Horse Council counts only living listed horse allies", s16 damage)
{
    u32 alive;

    PARAMETRIZE { alive = 1; }
    PARAMETRIZE { alive = 5; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HORSE_COUNCIL); Attack(200); }
        PLAYER(SPECIES_TAUROS_PALDEA_BLAZE) { HP(alive >= 1 ? 1 : 0); }
        PLAYER(SPECIES_KELDEO_RESOLUTE) { HP(alive >= 2 ? 1 : 0); }
        PLAYER(SPECIES_FARIGIRAF) { HP(alive >= 3 ? 1 : 0); }
        PLAYER(SPECIES_DEERLING_WINTER) { HP(alive >= 4 ? 1 : 0); }
        PLAYER(SPECIES_DIALGA_ORIGIN) { HP(alive >= 5 ? 1 : 0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3636), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Flier makes Fly instant and stronger than Wing Attack")
{
    s16 flyDamage;
    s16 wingAttackDamage;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLIER); Attack(200); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(999); MaxHP(999); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_WING_ATTACK); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, player);
        HP_BAR(opponent, captureDamage: &flyDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WING_ATTACK, player);
        HP_BAR(opponent, captureDamage: &wingAttackDamage);
    } THEN {
        EXPECT_GT(flyDamage, wingAttackDamage);
    }
}

SINGLE_BATTLE_TEST("Brimstone bypasses Flash Fire")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRIMSTONE); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_FLASH_FIRE); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Stygian raises priority against sleeping targets")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STYGIAN); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(2)); Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF { ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent); }
    }
}

SINGLE_BATTLE_TEST("Omega forces outgoing and incoming type effectiveness", s16 damage)
{
    enum Ability playerAbility;
    enum Ability opponentAbility;

    PARAMETRIZE { playerAbility = ABILITY_OMEGA; opponentAbility = ABILITY_NONE; }
    PARAMETRIZE { playerAbility = ABILITY_NONE; opponentAbility = ABILITY_OMEGA; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_CONFUSION) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET) { Ability(playerAbility); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(opponentAbility); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSION); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(4.0), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Voidtouch ignores Reflect", s16 damage)
{
    u16 ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_VOIDTOUCH; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_REFLECT); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Voidtouch bypasses Safeguard")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_VOIDTOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SAFEGUARD); }
        TURN { MOVE(player, MOVE_TOXIC, hit: TRUE); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
    }
}

SINGLE_BATTLE_TEST("Voidtouch bypasses Mist")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_VOIDTOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); }
        TURN { MOVE(player, MOVE_GROWL); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Ritual absorbs Ghost moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_RITUAL); HP(80); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET) { SpAttack(200); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_BALL); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_RITUAL);
        HP_BAR(player, damage: -40);
    } THEN {
        EXPECT_EQ(player->hp, 120);
    }
}

SINGLE_BATTLE_TEST("Ritual raises Hex from 65 to 75 BP", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_RITUAL; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEX); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(75.0 / 65.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Overlock doubles the next Steel hit after Shift Gear", s16 damage)
{
    bool32 overlock;

    PARAMETRIZE { overlock = FALSE; }
    PARAMETRIZE { overlock = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(overlock ? ABILITY_OVERLOCK : ABILITY_NONE); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHIFT_GEAR); }
        TURN { MOVE(player, MOVE_METAL_CLAW); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Overload ignores Focus Sash")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_OVERLOAD); Attack(250); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); MaxHP(100); Defense(1); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(opponent->hp, 0);
    }
}

SINGLE_BATTLE_TEST("Overload ignores held evasion modifiers")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SCRATCH) == 100);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_OVERLOAD); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Solar Panel makes Electric moves always hit in sun")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOLAR_PANEL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_THUNDER, WITH_RNG(RNG_ACCURACY, FALSE)); }
    } SCENE {
        HP_BAR(opponent);
    }
}

#if MAX_MON_TRAITS > 1

SINGLE_BATTLE_TEST("Solar Panel recognizes Normal moves converted to Electric")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveType(MOVE_SLAM) == TYPE_NORMAL);
        ASSUME(GetMoveAccuracy(MOVE_SLAM) < 100);
        STARTING_WEATHER(B_WEATHER_SUN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SOLAR_PANEL); Innates(ABILITY_GALVANIZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLAM, player);
        HP_BAR(opponent);
    }
}
#endif

SINGLE_BATTLE_TEST("Enigma doubles Power moves", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_ENIGMA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); SpAttack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_GEM); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Burrower makes Dig instant and stronger than Earthquake")
{
    s16 digDamage;
    s16 earthquakeDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BURROWER); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIG); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &digDamage);
        HP_BAR(opponent, captureDamage: &earthquakeDamage);
    } THEN {
        EXPECT_GT(digDamage, earthquakeDamage);
    }
}

SINGLE_BATTLE_TEST("Diver makes Dive instant and stronger than Waterfall")
{
    s16 diveDamage;
    s16 waterfallDamage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DIVER); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
        TURN { MOVE(player, MOVE_WATERFALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &diveDamage);
        HP_BAR(opponent, captureDamage: &waterfallDamage);
    } THEN {
        EXPECT_GT(diveDamage, waterfallDamage);
    }
}

SINGLE_BATTLE_TEST("Last Stand boosts attack damage", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_LAST_STAND; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Last Stand costs 10 percent max HP after attacking")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LAST_STAND); HP(100); MaxHP(100); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 90);
    }
}

SINGLE_BATTLE_TEST("Debilitate drains 3 extra PP from opposing moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_POUND, 10}); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_DEBILITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } THEN {
        EXPECT_EQ(player->pp[0], 6);
    }
}

SINGLE_BATTLE_TEST("Flexible makes two-turn attacks instant")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLEXIBLE); Attack(200); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLY); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Rockstorm makes Rock moves bypass accuracy in sand")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_ROCK_THROW) < 100);
        STARTING_WEATHER(B_WEATHER_SANDSTORM);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROCKSTORM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_THROW, player);
        HP_BAR(opponent);
    }
}

#if MAX_MON_TRAITS > 1

SINGLE_BATTLE_TEST("Rockstorm recognizes Normal moves converted to Rock")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveType(MOVE_SLAM) == TYPE_NORMAL);
        ASSUME(GetMoveAccuracy(MOVE_SLAM) < 100);
        STARTING_WEATHER(B_WEATHER_SANDSTORM);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_ROCKSTORM); Innates(ABILITY_ROCK_ATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLAM, player);
        HP_BAR(opponent);
    }
}
#endif

SINGLE_BATTLE_TEST("Windcaller boosts Flying-type damage by 30 percent", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_WINDCALLER; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_GUST) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GUST); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Windcaller makes Tailwind last 6 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_WINDCALLER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        MESSAGE("The Tailwind blew from behind your team!");
    } THEN {
        EXPECT_EQ(gSideTimers[B_SIDE_PLAYER].tailwindTimer, 5);
    }
}

SINGLE_BATTLE_TEST("Siegebreaker attacks use two-thirds of Defense", s16 damage)
{
    enum Ability ability;
    u16 attack;
    u16 defense;

    PARAMETRIZE
    {
        ability = ABILITY_SIEGEBREAKER;
        attack = 50;
        defense = 150;
    }
    PARAMETRIZE
    {
        ability = ABILITY_NONE;
        attack = 100;
        defense = 50;
    }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET)
        {
            Ability(ability);
            Attack(attack);
            Defense(defense);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_DAMAGE_MODIFIER, 0));
        }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
