#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"
#include "process_record.h"

#ifdef OLED_ENABLE
#    include "oled/oled_setup.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "tap_dance.h"
#endif

enum layer_names {
    _QWERTY,
    _COLEMAKDH,
#ifdef STENO_ENABLE
    _PLOVER,
#endif
    _NAV,
    _SYM,
    _FUNC,
    _NUMPAD,
    _ADJUST,
};
