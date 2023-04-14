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
                               SYM,     SPC_FUNC,               KC_ENT,     NAV                              \
    )

#define LAYOUT_ferris_base_wrapper(...) LAYOUT_ferris_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ferris_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        ____________QWERTY_HOME_MODE_L2____________, ____________QWERTY_HOME_MODE_R2____________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAKDH] = LAYOUT_ferris_base_wrapper(
        ________________COLEMAK_DH_L1______________, ________________COLEMAK_DH_R1______________,
        __________COLEMAK_DH_HOME_MODE_L2__________, __________COLEMAK_DH_HOME_MODE_R2__________,
        ________________COLEMAK_DH_L3______________, ________________COLEMAK_DH_R3______________
    ),

    [_SYM] = LAYOUT_ferris_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________SYMBOL_L3_________________, _________________SYMBOL_R3_________________,
        _________________SYMBOL_L2_________________, _________________SYMBOL_R2_________________,
    ),

    [_FUNC] = LAYOUT_ferris_base_wrapper(
        __________________FUNC_L1__________________, __________________FUNC_R1__________________,
        ___________________EMPTY___________________, ___________________EMPTY___________________,
        ___________________EMPTY___________________, ___________________EMPTY___________________,
    ),

    [_NAV] = LAYOUT_ferris_base_wrapper(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    ),

    [_ADJUST] = LAYOUT_ferris_base_wrapper(
        _________________ADJUST_L1_________________, ___________________EMPTY___________________,
        _________________ADJUST_L2_________________, ___________________ARROW___________________,
        _________________ADJUST_L3_________________, _________________ADJUST_R3_________________,
    )
};
// clang-formatter on
