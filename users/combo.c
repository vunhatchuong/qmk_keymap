#include "ronny.h"

enum combos { WE_ESC, XC_TAB, IO_BSPC, COMMDOT_DEL, COMBO_LENGTH };
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM we_combo[]      = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM xc_combo[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM io_combo[]      = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [WE_ESC]      = COMBO(we_combo, KC_ESC),
    [XC_TAB]      = COMBO(xc_combo, KC_TAB),
    [IO_BSPC]     = COMBO(io_combo, KC_BSPC),
    [COMMDOT_DEL] = COMBO(commdot_combo, KC_DEL),
};
