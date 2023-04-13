#include QMK_KEYBOARD_H
#include "ronny.h"

// clang-format off
#define LAYOUT_ferris_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    K01,     K02,     K03,     K04,     K05,                       K06,     K07,     K08,     K09,     K0A,  \
    K11,     K12,     K13,     K14,     K15,                       K16,     K17,     K18,     K19,     K1A,  \
    K21,     K22,     K23,     K24,     K25,                       K26,     K27,     K28,     K29,     K2A,  \
                               SYM,     KC_SPC,                 KC_ENT,     NAV                              \
    )

#define LAYOUT_ferris_base_wrapper(...) LAYOUT_ferris_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ferris_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAKDH] = LAYOUT_ferris_base_wrapper(
        ________________COLEMAK_DH_L1______________, ________________COLEMAK_DH_R1______________,
        ________________COLEMAK_DH_L2______________, ________________COLEMAK_DH_R2______________,
        ________________COLEMAK_DH_L3______________, ________________COLEMAK_DH_R3______________
    ),

    [_SYM] = LAYOUT_ferris_base_wrapper(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, QK_BOOT,
    ),

    [_NAV] = LAYOUT_ferris_base_wrapper(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    ),

    [_ADJUST] = LAYOUT_ferris_base_wrapper(
        TD_BOOT,  TD_QWERTY,  TD_COLEMAKDH,  TD_GAME, XXXXXXX       ___________________EMPTY___________________,
        ___________________EMPTY___________________,                ___________________EMPTY___________________,
        _______,  _______,  _______,  _______,  KC_CAPS,            ___________________ARROW___________________,
        ___________________EMPTY___________________,                _________________ADJUST_R3_________________,
    )
};
// clang-formatter on
