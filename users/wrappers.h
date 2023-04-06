#pragma once
#include "ronny.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#   define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

// clang-format off

#define ___________________BLANK___________________      _______, _______, _______, _______, _______

#define _________________QWERTY_L1_________________      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________      KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________COLEMAK_DH_L1______________      KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ________________COLEMAK_DH_L2______________      KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ________________COLEMAK_DH_L3______________      KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ________________COLEMAK_DH_R1______________      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ________________COLEMAK_DH_R2______________      KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ________________COLEMAK_DH_R3______________      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define ____________QWERTY_HOME_MODE_L1____________      KC_Q,            KC_W,            KC_E,            KC_R,            KC_T
#define ____________QWERTY_HOME_MODE_L2____________      LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G
#define ____________QWERTY_HOME_MODE_L3____________      KC_Z,            ALGR_T(KC_X),    KC_C,            KC_V,            KC_B

#define ____________QWERTY_HOME_MODE_R1____________      KC_Y,            KC_U,            KC_I,            KC_O,            KC_P
#define ____________QWERTY_HOME_MODE_R2____________      KC_H,            LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L),    LGUI_T(KC_SCLN)
#define ____________QWERTY_HOME_MODE_R3____________      KC_N,            KC_M,            KC_COMM,         ALGR_T(KC_DOT),  KC_SLASH

#define __________COLEMAK_DH_HOME_MODE_L1__________      KC_Q,            KC_W,            KC_F,            KC_P,            KC_B
#define __________COLEMAK_DH_HOME_MODE_L2__________      LGUI_T(KC_A),    LALT_T(KC_R),    LCTL_T(KC_S),    LSFT_T(KC_T),    KC_G
#define __________COLEMAK_DH_HOME_MODE_L3__________      KC_Z,            ALGR_T(KC_X),    KC_C,            KC_D,            KC_V

#define __________COLEMAK_DH_HOME_MODE_R1__________      KC_J,            KC_L,            KC_U,            KC_Y,            KC_SCLN
#define __________COLEMAK_DH_HOME_MODE_R2__________      KC_M,            LSFT_T(KC_N),    LCTL_T(KC_E),    LALT_T(KC_I),    LGUI_T(KC_O)
#define __________COLEMAK_DH_HOME_MODE_R3__________      KC_K,            KC_H,            KC_COMM,         ALGR_T(KC_DOT),  KC_SLASH

#define ________________NUMBER_LEFT________________      KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________      KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNC_LEFT_________________      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________LOWER_L1__________________      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________      _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________      _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________      _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT

#define _________________RAISE_L1__________________      ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_L3__________________      ___________________BLANK___________________

#define _________________RAISE_R1__________________      ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________RAISE_R3__________________      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END

#define _________________ADJUST_L1_________________      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________      MU_TOGG , TG(_GAMING), AU_ON,   AU_OFF,  AG_NORM
#define _________________ADJUST_L3_________________      RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, _______

#define _________________ADJUST_R1_________________      _______, _______, _______, _______, _______
#define _________________ADJUST_R2_________________      RESET,   CG_TOGG, _______, _______, _______
#define _________________ADJUST_R3_________________      _______, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY

#define _________________MOUSE_NAV_________________      KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
#define ________________MOUSE_WHEEL________________      KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R
#define _________________MOUSE_BTN_________________      KC_BTN1, KC_BTN2, KC_BTN3, KC_NO,   KC_NO

#define ____________________NAV____________________      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// clang-format on
