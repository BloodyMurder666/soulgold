#include "global.h"
#include "event_data.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Martyr heals remaining allies when it faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MARTYR); HP(1); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } THEN {
        EXPECT_EQ(playerRight->hp, 75);
    }
}

SINGLE_BATTLE_TEST("Martyr has no ally to heal in single battles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MARTYR); HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(player->hp, 0);
    }
}

SINGLE_BATTLE_TEST("Faintrattle badly poisons only contact attackers that knock it out")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_SCRATCH; }
    GIVEN {
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FAINTRATTLE); HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, move); }
    } THEN {
        if (move == MOVE_SCRATCH)
            EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
        else
            EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Haunted blocks real major status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HAUNTED); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Haunted counts as statused for Facade", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_HAUNTED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FACADE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Haunted counts as statused for Hex", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_BIG_PECKS; }
    PARAMETRIZE { ability = ABILITY_HAUNTED; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEX); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Mending can cure status and heal at end of turn")
{
    PASSES_RANDOMLY(30, 100, RNG_MENDING);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MENDING); HP(80); MaxHP(100); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_GT(player->hp, 80);
    }
}

SINGLE_BATTLE_TEST("Mending does not heal without its ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); HP(80); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->hp, 80);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Mending records the displayed innate instead of the main ability")
{
    PASSES_RANDOMLY(30, 100, RNG_MENDING);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BIG_PECKS); Innates(ABILITY_MENDING); HP(80); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(gBattleHistory->abilities[B_POSITION_PLAYER_LEFT], ABILITY_MENDING);
    }
}
#endif

SINGLE_BATTLE_TEST("Plaguetouch can inflict a random major status with contact moves")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLAGUETOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_NE(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Plaguetouch ignores non-contact moves")
{
    GIVEN {
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLAGUETOUCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Mirage can confuse targets during sun only")
{
    PASSES_RANDOMLY(25, 100, RNG_MIRAGE);
    GIVEN {
        STARTING_WEATHER(B_WEATHER_SUN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MIRAGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns > 0);
    }
}

SINGLE_BATTLE_TEST("Mirage does not confuse outside sun")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MIRAGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns == 0);
    }
}

SINGLE_BATTLE_TEST("Mirage does not confuse with status moves in sun")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_SUN_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MIRAGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns == 0);
    }
}

SINGLE_BATTLE_TEST("Blizzard Heart can freeze or frostbite with Ice moves during icy weather")
{
    PASSES_RANDOMLY(20, 100, RNG_BLIZZARD_HEART);
    GIVEN {
        ASSUME(GetMoveType(MOVE_ICE_SHARD) == TYPE_ICE);
        STARTING_WEATHER(B_WEATHER_HAIL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLIZZARD_HEART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ICE_SHARD); }
    } THEN {
        EXPECT(opponent->status1 & (STATUS1_FREEZE | STATUS1_FROSTBITE));
    }
}

SINGLE_BATTLE_TEST("Blizzard Heart ignores non-Ice moves")
{
    GIVEN {
        STARTING_WEATHER(B_WEATHER_HAIL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLIZZARD_HEART); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Channel Earth heals at end of turn only while terrain is active", u16 hp)
{
    bool32 terrain;

    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    if (terrain)
        SetStartingStatus(STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CHANNEL_EARTH); HP(80); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        results[i].hp = player->hp;
        ResetStartingStatuses();
    } FINALLY {
        EXPECT_EQ(results[0].hp, 80);
        EXPECT_GT(results[1].hp, 80);
    }
}

SINGLE_BATTLE_TEST("Maim and Mend heals after critical hits only", u16 hp)
{
    bool32 critical;

    PARAMETRIZE { critical = FALSE; }
    PARAMETRIZE { critical = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MAIM_AND_MEND); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: critical); }
    } THEN {
        results[i].hp = player->hp;
    } FINALLY {
        EXPECT_EQ(results[0].hp, 50);
        EXPECT_GT(results[1].hp, 50);
    }
}

SINGLE_BATTLE_TEST("Wishmaker casts Wish on entry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_WISHMAKER); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { }
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WISHMAKER);
        MESSAGE("Wobbuffet's wish came true!");
        HP_BAR(player, damage: -50);
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}

DOUBLE_BATTLE_TEST("Flameburst burns the opposing side when the user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FLAMEBURST); HP(1); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); Speed(100); }
        OPPONENT(SPECIES_WYNAUT) { Speed(90); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_FLAMEBURST);
    } THEN {
        EXPECT(opponentLeft->status1 & STATUS1_BURN);
        EXPECT(opponentRight->status1 & STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Brand of Torment has a 30 percent chance to torment contact attackers")
{
    PASSES_RANDOMLY(3, 10, RNG_BRAND_OF_TORMENT);
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRAND_OF_TORMENT); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH, allowed: FALSE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BRAND_OF_TORMENT);
        MESSAGE("The opposing Wynaut was subjected to torment!");
        MESSAGE("The opposing Wynaut used Celebrate!");
    } THEN {
        EXPECT(opponent->volatiles.torment);
    }
}

SINGLE_BATTLE_TEST("Brand of Torment only triggers on contact")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BRAND_OF_TORMENT); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, move, WITH_RNG(RNG_BRAND_OF_TORMENT, TRUE)); }
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(player, ABILITY_BRAND_OF_TORMENT);
        } else {
            NONE_OF { ABILITY_POPUP(player, ABILITY_BRAND_OF_TORMENT); }
        }
    } THEN {
        bool32 isTormented = opponent->volatiles.torment;
        EXPECT_EQ(isTormented, MoveMakesContact(move));
    }
}

SINGLE_BATTLE_TEST("Jade Bloom heals and raises an eligible special stat")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_JADE_BLOOM); HP(80); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 90);
        EXPECT(player->statStages[STAT_SPATK] == DEFAULT_STAT_STAGE + 1 || player->statStages[STAT_SPDEF] == DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Permafrost prevents burns and Attack drops")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PERMAFROST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
        TURN { MOVE(opponent, MOVE_GROWL); }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Permafrost can freeze or frostbite on damaging attacks")
{
    PASSES_RANDOMLY(20, 100, RNG_PERMAFROST);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PERMAFROST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_ICY_ANY);
    }
}

SINGLE_BATTLE_TEST("Glacial raises Sp. Def on entry and heals in hail")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_GLACIAL); HP(80); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HAIL); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Frost Nova always freezes the KOing attacker")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FROST_NOVA); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_FREEZE);
        EXPECT(!(opponent->status1 & STATUS1_FROSTBITE));
    }
}

SINGLE_BATTLE_TEST("Frost Nova guarantees exactly one frozen turn")
{
    GIVEN {
        ASSUME(MoveThawsUser(MOVE_FLAME_WHEEL));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_FROST_NOVA); HP(1); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_FLAME_WHEEL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("The opposing Wobbuffet is frozen solid!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAME_WHEEL, opponent);
    } THEN {
        EXPECT(!(opponent->status1 & STATUS1_ICY_ANY));
        EXPECT(!opponent->volatiles.frostNovaTimer);
    }
}

SINGLE_BATTLE_TEST("Spectral Drain heals from Ground and Ghost damage and blocks Leech Seed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SPECTRAL_DRAIN); HP(80); MaxHP(160); Attack(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEECH_SEED); }
        TURN { MOVE(player, MOVE_SHADOW_PUNCH); }
    } THEN {
        EXPECT(!player->volatiles.leechSeed);
        EXPECT(player->hp > 80);
    }
}

SINGLE_BATTLE_TEST("Blazing Sun burns with damaging Fire moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_BLAZING_SUN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_BURN);
    }
}

SINGLE_BATTLE_TEST("Dust Devil can confuse on damaging attacks")
{
    PASSES_RANDOMLY(15, 100, RNG_DUST_DEVIL);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DUST_DEVIL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT(opponent->volatiles.confusionTurns > 0);
    }
}

SINGLE_BATTLE_TEST("Reef Warden heals 50 percent on switch-out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REEF_WARDEN); HP(80); MaxHP(160); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 160);
    }
}

SINGLE_BATTLE_TEST("Reef Warden still heals on switch-out after taking contact")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REEF_WARDEN); HP(120); MaxHP(160); Defense(200); Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(1); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 160);
    }
}

SINGLE_BATTLE_TEST("Reef Warden prevents contact attackers from healing")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REEF_WARDEN); Defense(200); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(80); MaxHP(160); Attack(1); Speed(2); Item(ITEM_LEFTOVERS); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_REEF_WARDEN);
        MESSAGE("The opposing Wobbuffet was prevented from healing!");
        NONE_OF { HP_BAR(opponent); }
    } THEN {
        EXPECT_EQ(opponent->hp, 80);
        EXPECT(opponent->volatiles.healBlock);
    }
}

SINGLE_BATTLE_TEST("Plasma Surge paralyzes with attacks during Electric Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLASMA_SURGE); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_PARALYSIS);
    }
}

SINGLE_BATTLE_TEST("Plasma Surge does not paralyze outside Electric Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLASMA_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Hunter makes Glare confuse and paralyze")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HUNTER); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_GLARE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT(opponent->status1 & STATUS1_PARALYSIS);
        EXPECT(opponent->volatiles.confusionTurns > 0);
    }
}

SINGLE_BATTLE_TEST("Hunter boosts Attack by 50 percent while a foe is paralyzed", s16 damage)
{
    u32 status;

    PARAMETRIZE { status = STATUS1_NONE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HUNTER); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Rejuvenation heals if no damage was taken this turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REJUVENATION); HP(80); MaxHP(100); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Rejuvenation remembers an earlier hit after the holder acts")
{
    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REJUVENATION); HP(80); MaxHP(100); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(player->hp, 80 - damage);
    }
}

SINGLE_BATTLE_TEST("Consume heals 50 percent max HP after knocking out a foe")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CONSUME); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); SEND_OUT(opponent, 1); }
    } SCENE {
        MESSAGE("The opposing Wynaut fainted!");
        ABILITY_POPUP(player, ABILITY_CONSUME);
        HP_BAR(player, damage: -50);
    }
}

SINGLE_BATTLE_TEST("Lifesteal restores one eighth of damage dealt")
{
    s16 damage;
    s16 healing;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIFESTEAL); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage);
        ABILITY_POPUP(player, ABILITY_LIFESTEAL);
        HP_BAR(player, captureDamage: &healing);
    } THEN {
        EXPECT_EQ(damage / 8, -healing);
    }
}

SINGLE_BATTLE_TEST("Haunting gives Ghost-type attacks a 20 percent chance to flinch")
{
    PASSES_RANDOMLY(20, 100, RNG_HAUNTING);
    GIVEN {
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HAUNTING); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_BALL); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_BALL, player);
        MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
    }
}
