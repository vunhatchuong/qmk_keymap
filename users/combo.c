#include "ronny.h"

enum combo_events {
    // Combo events will be with colemak homerow mod as base.
    WF_ESC,
    XC_TAB,
    UY_BSPC,
    COMMDOT_DEL,
#ifdef COMBO_SYMBOL_ENABLE
    SCLNO_BSLS,
    OSLASH_PIPE,
    MN_MINS,
    KH_UNDS,
    QA_GRV,
    AZ_TILD,
#endif
};

const uint16_t PROGMEM W_F_COMBO[]      = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM X_C_COMBO[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM U_Y_COMBO[]      = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM COMM_DOT_COMBO[] = {KC_COMM, KC_DOT, COMBO_END};

#ifdef COMBO_SYMBOL_ENABLE
// Right hand side
const uint16_t PROGMEM SCLN_O_COMBO[]  = {KC_SCLN, GUI_O, COMBO_END};
const uint16_t PROGMEM O_SLASH_COMBO[] = {GUI_O, KC_SLASH, COMBO_END};
const uint16_t PROGMEM M_N_COMBO[]     = {KC_M, CTL_N, COMBO_END};
const uint16_t PROGMEM K_H_COMBO[]     = {KC_K, KC_H, COMBO_END};

// Left hand side
const uint16_t PROGMEM Q_A_COMBO[] = {KC_Q, GUI_A, COMBO_END};
const uint16_t PROGMEM A_Z_COMBO[] = {GUI_A, KC_Z, COMBO_END};
#endif

combo_t key_combos[] = {
    // Controls
    [WF_ESC]      = COMBO(W_F_COMBO, KC_ESC),
    [XC_TAB]      = COMBO(X_C_COMBO, KC_TAB),
    [UY_BSPC]     = COMBO(U_Y_COMBO, KC_BSPC),
    [COMMDOT_DEL] = COMBO(COMM_DOT_COMBO, KC_DEL),
#ifdef COMBO_SYMBOL_ENABLE
    // Right hand side
    [SCLNO_BSLS]  = COMBO(SCLN_O_COMBO, KC_BSLS),
    [OSLASH_PIPE] = COMBO(O_SLASH_COMBO, KC_PIPE),
    [MN_MINS]     = COMBO(M_N_COMBO, KC_MINS),
    [KH_UNDS]     = COMBO(K_H_COMBO, KC_UNDS),
    // Left hand side
    [QA_GRV]  = COMBO(Q_A_COMBO, KC_GRV),
    [AZ_TILD] = COMBO(A_Z_COMBO, KC_TILD),
#endif
};
