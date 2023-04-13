#pragma once
#include "ronny.h"

// clang-format off
enum custom_keycodes {
    // Macro for: ("
    O_PRQOT = SAFE_RANGE,
    // Macro for: ")
    C_PRQOT,
    // Macro for: ["
    O_BRQOT,
    // Macro for: "]
    C_BRQOT,
    };
// clang-format on

// ---
// Layers
#define QWERTY DF(_QWERTY)
#define COLEMAKDH DF(_COLEMAKDH)
#define NAV MO(_NAV)
#define MEDIA MO(_MEDIA)
#define GAME DF(_GAME)
#define SYM MO(_SYM)
#define FUNC MO(_FUNC)
#define ADJUST MO(_ADJUST)

// ---
// QWERTY home row mods
// Left-hand
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// COLEMAK DH home row mods
// Left-hand
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
// Not using CTL_T because redefined error
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// ----------------------------------------------------------------
// Shorcuts
#define CTL_ESC CTL_T(KC_ESC)

#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)

#define KC_RESET QK_BOOT
#define KC_RST KC_RESET

#define VIM_B LCTL(KC_LEFT)
#define VIM_W LCTL(KC_RIGHT)

// Tabs navigation
#define C_TAB C(KC_TAB)
#define CS_TAB C(S(KC_TAB))
#define C_W C(KC_W)
#define CS_T C(S(KC_T))
#define C_T C(KC_T)
