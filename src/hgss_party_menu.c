#include "global.h"
#include "constants/party_menu.h"

#if PARTY_MENU_STYLE_OPTION

// The DS party-menu implementation is selected at compile time. Build a
// second private copy with the HGSS data, alongside party_menu.c's BW copy.
#define PARTY_MENU_STYLE PARTY_MENU_STYLE_HGSS
#define PARTY_MENU_VARIANT_HGSS
#include "party_menu.c"

#endif // PARTY_MENU_STYLE_OPTION
