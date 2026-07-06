enum
{
    PAGE_TITLE,
    PAGE_SOULGOLD_DEVELOPER,
    PAGE_SOULGOLD_PLAYTESTERS_1,
    PAGE_SOULGOLD_PLAYTESTERS_2,
    PAGE_SOULGOLD_PLAYTESTERS_3,
    PAGE_HNS_CREATOR,
    PAGE_EXPANSION_PORT,
    PAGE_HNS_DEVS_1,
    PAGE_HNS_DEVS_2,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_SPECIAL_THANKS_4,
    PAGE_SPECIAL_THANKS_5,
    PAGE_SPECIAL_THANKS_6,
    PAGE_SPECIAL_THANKS_7,
    PAGE_SPECIAL_THANKS_8,
    PAGE_SPECIAL_THANKS_9,
    PAGE_SPECIAL_THANKS_10,
    PAGE_SPECIAL_THANKS_11,
    PAGE_SPECIAL_THANKS_12,
    PAGE_SPECIAL_THANKS_13,
    PAGE_COUNT
};

#define ENTRIES_PER_PAGE 5

#define DEFINE_CREDITS_ENTRY(identifier, value, title)                          \
    static const u8 sCreditsText_##identifier[] = _(value);                     \
    static const struct CreditsEntry sCreditsEntry_##identifier =               \
    {                                                                            \
        .unk = 11,                                                               \
        .isTitle = title,                                                        \
        .text = sCreditsText_##identifier,                                       \
    }

DEFINE_CREDITS_ENTRY(EmptyString, "", FALSE);
DEFINE_CREDITS_ENTRY(PkmnSoulGold, "Pokémon Soulgold", TRUE);
DEFINE_CREDITS_ENTRY(Credits, "Credits", TRUE);

DEFINE_CREDITS_ENTRY(SoulgoldDeveloper, "Soulgold Developer", TRUE);
DEFINE_CREDITS_ENTRY(Rahtak, "Rahtak", FALSE);

DEFINE_CREDITS_ENTRY(SoulgoldPlaytesters, "Soulgold playtesters", TRUE);
DEFINE_CREDITS_ENTRY(Athena, "Athena", FALSE);
DEFINE_CREDITS_ENTRY(Baia, "Baia", FALSE);
DEFINE_CREDITS_ENTRY(Hanoe, "Hanoe", FALSE);
DEFINE_CREDITS_ENTRY(Dracandre, "Dracandre", FALSE);
DEFINE_CREDITS_ENTRY(Simpli, "Simpli", FALSE);
DEFINE_CREDITS_ENTRY(Nem, "Nem", FALSE);
DEFINE_CREDITS_ENTRY(Jan, "Jan", FALSE);
DEFINE_CREDITS_ENTRY(Wook, "Wook", FALSE);
DEFINE_CREDITS_ENTRY(Dvs, "Dvs", FALSE);
DEFINE_CREDITS_ENTRY(Tylarie, "Tylarie", FALSE);

DEFINE_CREDITS_ENTRY(HnSCreator, "Pokemon Heart and Soul Creator", TRUE);
DEFINE_CREDITS_ENTRY(LilDill, "LIL DILL", FALSE);

DEFINE_CREDITS_ENTRY(ExpansionPort, "Expansion Port by", TRUE);
DEFINE_CREDITS_ENTRY(IAmAwesome2, "IAmAwesome2", FALSE);

DEFINE_CREDITS_ENTRY(HnSDevs, "H&S Devs", TRUE);
DEFINE_CREDITS_ENTRY(InfiniteBacon42, "InfiniteBacon42", FALSE);
DEFINE_CREDITS_ENTRY(Exclsior, "Exclsior", FALSE);
DEFINE_CREDITS_ENTRY(TixoRebel, "TixoRebel", FALSE);
DEFINE_CREDITS_ENTRY(Phantonomy, "Phantonomy", FALSE);
DEFINE_CREDITS_ENTRY(DaniRainbow, "DaniRainbow", FALSE);
DEFINE_CREDITS_ENTRY(Resetes, "Resetes", FALSE);
DEFINE_CREDITS_ENTRY(Jozuno, "Jozuno", FALSE);

// Names credited in README.md, in the order in which they appear there.
DEFINE_CREDITS_ENTRY(SpecialThanks, "Special thanks to", TRUE);
DEFINE_CREDITS_ENTRY(HnSDevTeam, "HnS Dev Team", FALSE);
DEFINE_CREDITS_ENTRY(smithk200, "smithk200", FALSE);
DEFINE_CREDITS_ENTRY(RafaelSanna, "Rafael Sanna", FALSE);
DEFINE_CREDITS_ENTRY(RHH, "RHH", FALSE);
DEFINE_CREDITS_ENTRY(ExpansionDevs, "pokeemerald-expansion dev team", FALSE);
DEFINE_CREDITS_ENTRY(TeamAquaHideout, "TeamAquaHideout", FALSE);
DEFINE_CREDITS_ENTRY(Estellar, "Estellar", FALSE);
DEFINE_CREDITS_ENTRY(PokemonSanFran, "PokemonSanFran/PSF", FALSE);
DEFINE_CREDITS_ENTRY(LinathanZel, "LinathanZel", FALSE);
DEFINE_CREDITS_ENTRY(Kasenn, "Kasenn", FALSE);
DEFINE_CREDITS_ENTRY(bassforte123, "bassforte123", FALSE);
DEFINE_CREDITS_ENTRY(PurrfectDoodle, "PurrfectDoodle", FALSE);
DEFINE_CREDITS_ENTRY(RavePossum, "RavePossum", FALSE);
DEFINE_CREDITS_ENTRY(Ruki, "Ruki", FALSE);
DEFINE_CREDITS_ENTRY(Greenphx9, "Greenphx9", FALSE);
DEFINE_CREDITS_ENTRY(devolov, "devolov", FALSE);
DEFINE_CREDITS_ENTRY(fisham33, "fisham33", FALSE);
DEFINE_CREDITS_ENTRY(TheXaman, "TheXaman", FALSE);
DEFINE_CREDITS_ENTRY(Lhea, "Lhea", FALSE);
DEFINE_CREDITS_ENTRY(Mont, "Mont", FALSE);
DEFINE_CREDITS_ENTRY(Jordan, "Jordan", FALSE);
DEFINE_CREDITS_ENTRY(destvol, "destvol", FALSE);
DEFINE_CREDITS_ENTRY(Leob0505, "Leob0505", FALSE);
DEFINE_CREDITS_ENTRY(Wiz1989, "Wiz1989", FALSE);
DEFINE_CREDITS_ENTRY(Mudskip, "Mudskip", FALSE);
DEFINE_CREDITS_ENTRY(gruntLucas, "grunt-lucas", FALSE);
DEFINE_CREDITS_ENTRY(archie, "archie", FALSE);
DEFINE_CREDITS_ENTRY(drazden, "drazden", FALSE);
DEFINE_CREDITS_ENTRY(Ghoulslash, "Ghoulslash", FALSE);
DEFINE_CREDITS_ENTRY(FosterProgramming, "James/FosterProgramming", FALSE);
DEFINE_CREDITS_ENTRY(Ipatix, "Ipatix", FALSE);
DEFINE_CREDITS_ENTRY(Kyledove, "Kyledove", FALSE);
DEFINE_CREDITS_ENTRY(Hyo, "Hyo", FALSE);
DEFINE_CREDITS_ENTRY(PoffinCase, "Poffin Case", FALSE);
DEFINE_CREDITS_ENTRY(HashtagMarky, "HashtagMarky", FALSE);
DEFINE_CREDITS_ENTRY(Pokeabbie, "Pokeabbie", FALSE);
DEFINE_CREDITS_ENTRY(MrDollStreak, "MrDollStreak", FALSE);
DEFINE_CREDITS_ENTRY(PKMNTrainerRick, "PKMNTrainerRick", FALSE);
DEFINE_CREDITS_ENTRY(Whackahack, "Whackahack", FALSE);
DEFINE_CREDITS_ENTRY(Omega, "Omega", FALSE);
DEFINE_CREDITS_ENTRY(agsmgmaster64, "agsmgmaster64", FALSE);
DEFINE_CREDITS_ENTRY(heypc, "heypc", FALSE);
DEFINE_CREDITS_ENTRY(aarantMerrp, "aarant/merrp", FALSE);
DEFINE_CREDITS_ENTRY(msikma, "msikma", FALSE);
DEFINE_CREDITS_ENTRY(leparagon, "leparagon", FALSE);
DEFINE_CREDITS_ENTRY(LarryTurbo, "LarryTurbo", FALSE);
DEFINE_CREDITS_ENTRY(Phasma, "Phasma", FALSE);
DEFINE_CREDITS_ENTRY(PokerogueTeam, "Pokerogue Team", FALSE);
DEFINE_CREDITS_ENTRY(StarrWolf, "StarrWolf", FALSE);
DEFINE_CREDITS_ENTRY(SomeonealiveQN, "Someonealive-QN", FALSE);
DEFINE_CREDITS_ENTRY(Ezerart, "Ezerart", FALSE);
DEFINE_CREDITS_ENTRY(mbcmechachu, "mbcmechachu", FALSE);

#undef DEFINE_CREDITS_ENTRY

#define _ &sCreditsEntry_EmptyString
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    [PAGE_TITLE] = {
        _,
        &sCreditsEntry_PkmnSoulGold,
        &sCreditsEntry_Credits,
        _,
        _,
    },
    [PAGE_SOULGOLD_DEVELOPER] = {
        _,
        &sCreditsEntry_SoulgoldDeveloper,
        &sCreditsEntry_Rahtak,
        _,
        _,
    },
    [PAGE_SOULGOLD_PLAYTESTERS_1] = {
        &sCreditsEntry_SoulgoldPlaytesters,
        &sCreditsEntry_Athena,
        &sCreditsEntry_Hanoe,
        &sCreditsEntry_Baia,
        &sCreditsEntry_Simpli,
    },
    [PAGE_SOULGOLD_PLAYTESTERS_2] = {
        &sCreditsEntry_SoulgoldPlaytesters,
        &sCreditsEntry_Nem,
        &sCreditsEntry_Dracandre,
        &sCreditsEntry_Wook,
        &sCreditsEntry_Dvs,
    },
    [PAGE_SOULGOLD_PLAYTESTERS_3] = {
        _,
        &sCreditsEntry_SoulgoldPlaytesters,
        &sCreditsEntry_Tylarie,
        &sCreditsEntry_Jan,
        _,
    },
    [PAGE_HNS_CREATOR] = {
        _,
        &sCreditsEntry_HnSCreator,
        &sCreditsEntry_LilDill,
        _,
        _,
    },
    [PAGE_EXPANSION_PORT] = {
        _,
        &sCreditsEntry_ExpansionPort,
        &sCreditsEntry_IAmAwesome2,
        _,
        _,
    },
    [PAGE_HNS_DEVS_1] = {
        &sCreditsEntry_HnSDevs,
        &sCreditsEntry_InfiniteBacon42,
        &sCreditsEntry_Exclsior,
        &sCreditsEntry_TixoRebel,
        &sCreditsEntry_Phantonomy,
    },
    [PAGE_HNS_DEVS_2] = {
        &sCreditsEntry_HnSDevs,
        &sCreditsEntry_DaniRainbow,
        &sCreditsEntry_Resetes,
        &sCreditsEntry_Jozuno,
        _,
    },
    [PAGE_SPECIAL_THANKS_1] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_HnSDevTeam,
        &sCreditsEntry_smithk200,
        &sCreditsEntry_RafaelSanna,
        &sCreditsEntry_RHH,
    },
    [PAGE_SPECIAL_THANKS_2] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_ExpansionDevs,
        &sCreditsEntry_TeamAquaHideout,
        &sCreditsEntry_Estellar,
        &sCreditsEntry_PokemonSanFran,
    },
    [PAGE_SPECIAL_THANKS_3] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_LinathanZel,
        &sCreditsEntry_Kasenn,
        &sCreditsEntry_bassforte123,
        &sCreditsEntry_PurrfectDoodle,
    },
    [PAGE_SPECIAL_THANKS_4] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_RavePossum,
        &sCreditsEntry_Ruki,
        &sCreditsEntry_Greenphx9,
        &sCreditsEntry_devolov,
    },
    [PAGE_SPECIAL_THANKS_5] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_fisham33,
        &sCreditsEntry_TheXaman,
        &sCreditsEntry_Lhea,
        &sCreditsEntry_Mont,
    },
    [PAGE_SPECIAL_THANKS_6] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_Jordan,
        &sCreditsEntry_destvol,
        &sCreditsEntry_Leob0505,
        &sCreditsEntry_Wiz1989,
    },
    [PAGE_SPECIAL_THANKS_7] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_Mudskip,
        &sCreditsEntry_gruntLucas,
        &sCreditsEntry_archie,
        &sCreditsEntry_drazden,
    },
    [PAGE_SPECIAL_THANKS_8] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_Ghoulslash,
        &sCreditsEntry_FosterProgramming,
        &sCreditsEntry_Ipatix,
        &sCreditsEntry_Kyledove,
    },
    [PAGE_SPECIAL_THANKS_9] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_Hyo,
        &sCreditsEntry_PoffinCase,
        &sCreditsEntry_HashtagMarky,
        &sCreditsEntry_Pokeabbie,
    },
    [PAGE_SPECIAL_THANKS_10] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_MrDollStreak,
        &sCreditsEntry_PKMNTrainerRick,
        &sCreditsEntry_Whackahack,
        &sCreditsEntry_Omega,
    },
    [PAGE_SPECIAL_THANKS_11] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_agsmgmaster64,
        &sCreditsEntry_heypc,
        &sCreditsEntry_aarantMerrp,
        &sCreditsEntry_msikma,
    },
    [PAGE_SPECIAL_THANKS_12] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_leparagon,
        &sCreditsEntry_LarryTurbo,
        &sCreditsEntry_Phasma,
        &sCreditsEntry_PokerogueTeam,
    },
    [PAGE_SPECIAL_THANKS_13] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_StarrWolf,
        &sCreditsEntry_SomeonealiveQN,
        &sCreditsEntry_Ezerart,
        &sCreditsEntry_mbcmechachu,
    },
};
#undef _
