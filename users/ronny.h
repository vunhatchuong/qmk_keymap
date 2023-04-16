#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"
#include "process_record.h"

#ifdef XCASE_ENABLE
#    include "feature/xcase.h"
#endif

#ifdef QMK_VIM_ENABLE
#    include "feature/qmk-vim/src/vim.h"
#endif

#ifdef ANDREW_LEADER_ENABLE
#    include "features/andrewleader.h"
#endif

#ifdef OLED_ENABLE
#    include "oled/oled_setup.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "tap_dance.h"
#endif

enum layer_names {
    _QWERTY,
    _COLEMAKDH,
    _ARTSEY,
    _GAME,
    _NAV,
    _SYM,
    _FUNC,
    _NUMPAD,
    _ADJUST,
};
