#include "global.h"
#include "achievements.h"
#include "battle_setup.h"
#include "event_data.h"
#include "random.h"
#include "title_defense.h"
#include "test/test.h"
#include "constants/battle_setup.h"
#include "constants/event_objects.h"
#include "constants/field_mugshots.h"
#include "constants/opponents.h"

TEST("Title Defense selects the normal pool for defenses one through five")
{
    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_NONE);
    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 0);

    VarSet(VAR_TITLE_DEFENSE_WINS, 0);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_FALKNER);

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_NONE);
    VarSet(VAR_TITLE_DEFENSE_WINS, 4);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_FALKNER);
}

TEST("Title Defense adds Lance and Steven to the pool beginning with defense six")
{
    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_NONE);
    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 0);

    VarSet(VAR_TITLE_DEFENSE_WINS, 5);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_FALKNER);

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_NONE);
    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 8);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_LANCE);

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_NONE);
    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 9);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_STEVEN);
}

TEST("Title Defense prevents consecutive challengers")
{
    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 0);

    VarSet(VAR_TITLE_DEFENSE_WINS, 0);
    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_TITLE_DEFENSE_FALKNER);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_BUGSY);

    VarSet(VAR_TITLE_DEFENSE_WINS, 5);
    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_TITLE_DEFENSE_LANCE);
    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 8);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_STEVEN);

    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 0);
    TitleDefense_SelectChallenger();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_FALKNER);
}

TEST("Title Defense stages the selected challenger's overworld graphics")
{
    VarSet(VAR_TITLE_DEFENSE_WINS, 5);
    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_NONE);
    SetupRiggedRng(__LINE__, RNG_TITLE_DEFENSE_CHALLENGER, 9);

    TitleDefense_SelectChallenger();

    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_LAST_CHALLENGER), TRAINER_TITLE_DEFENSE_STEVEN);
    EXPECT_EQ(VarGet(VAR_OBJ_GFX_ID_0), OBJ_EVENT_GFX_STEVEN);
}

TEST("Title Defense derives mugshots from challenger overworld graphics")
{
    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_TITLE_DEFENSE_FALKNER);
    EXPECT_EQ(TitleDefense_GetCurrentMugshotId(), MUGSHOT_FALKNER);

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_TITLE_DEFENSE_LANCE);
    EXPECT_EQ(TitleDefense_GetCurrentMugshotId(), MUGSHOT_LANCE);

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_TITLE_DEFENSE_STEVEN);
    EXPECT_EQ(TitleDefense_GetCurrentMugshotId(), MUGSHOT_STEVEN);
}

TEST("Title Defense prepares a standard trainer battle")
{
    const struct TitleDefenseChallenger *challenger;

    VarSet(VAR_TITLE_DEFENSE_LAST_CHALLENGER, TRAINER_TITLE_DEFENSE_STEVEN);
    challenger = TitleDefense_GetCurrentChallenger();
    TitleDefense_PrepareBattle();

    EXPECT_EQ((u32)TRAINER_BATTLE_PARAM.mode, TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT);
    EXPECT(TRAINER_BATTLE_PARAM.playMusicA);
    EXPECT_EQ(TRAINER_BATTLE_PARAM.opponentA, TRAINER_TITLE_DEFENSE_STEVEN);
    EXPECT_EQ(TRAINER_BATTLE_PARAM.opponentB, TRAINER_NONE);
    EXPECT(TRAINER_BATTLE_PARAM.defeatTextA == challenger->defeatText);
}

TEST("Title Defense win counter increments and saturates")
{
    VarSet(VAR_TITLE_DEFENSE_WINS, 0);
    TitleDefense_IncrementWins();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_WINS), 1);
    EXPECT(Achievement_IsUnlocked(ACH_TITLE_DEFENDER));
    EXPECT(!Achievement_IsUnlocked(ACH_LONG_TERM_CAREER));
    EXPECT(!Achievement_IsUnlocked(ACH_UNDEFEATED_CHAMPION));

    VarSet(VAR_TITLE_DEFENSE_WINS, 4);
    TitleDefense_IncrementWins();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_WINS), 5);
    EXPECT(Achievement_IsUnlocked(ACH_LONG_TERM_CAREER));
    EXPECT(!Achievement_IsUnlocked(ACH_UNDEFEATED_CHAMPION));

    VarSet(VAR_TITLE_DEFENSE_WINS, 9);
    TitleDefense_IncrementWins();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_WINS), 10);
    EXPECT(Achievement_IsUnlocked(ACH_UNDEFEATED_CHAMPION));

    VarSet(VAR_TITLE_DEFENSE_WINS, MAX_u16);
    TitleDefense_IncrementWins();
    EXPECT_EQ(VarGet(VAR_TITLE_DEFENSE_WINS), MAX_u16);
}
