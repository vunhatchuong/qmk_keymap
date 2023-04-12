#pragma once
#include "ronny.h"

#ifdef TAP_DANCE_ENABLE
enum {
    BOOT_TD,
    QWERTY_TD,
    COLEMAKDH_TD,
    GAME_TD,
};
#endif

#define TD_BOOT TD(BOOT_TD)
#define TD_QWERTY TD(QWERTY_TD)
#define TD_COLEMAKDH TD(COLEMAKDH_TD)
#define TD_GAME TD(GAME_TD)
