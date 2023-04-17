#include "ronny.h"

uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _ARTSEY: return _ARTSEY;
        default: return _QWERTY;
    }
    return layer;  // important if default is not in case.
}

//clang-format off
enum combo_events {
    WE_ESC,
    XC_TAB,
    IO_BSPC,
    COMMDOT_DEL,
    LEADER,
    EM_EMAIL,
    DOTSLASH_UPDIR,
#ifdef STENO_LITE_ENABLE
    ENTEV_EVERY,
    ENTU_YOU,
    ENTA_AND,
    ENTW_WITH,
    ENTF_FOR,
    ENTH_HERE,
    ENTT_THE,
    ENTM_MENT,
    ENTG_ING,
    ENTO_OUGH,
    ENTOL_OULD,
    ENTI_ION,
    ENTIS_IONS,
    ENTTA_THAT,
    ENTK_KEY,
    ENTTS_THIS,
    ENTDN_DONT,
    ENTIT_IN_THE,
    HV_HAVE,
    QK_QMK,
    KB_KEYBOARD,
    WA_WHAT,
#endif
#ifdef COMBO_SYMBOL_ENABLE
    PSCLN_BSLS,
    SCLNSLASH_PIPE,
    HJ_MINS,
    NM_UNDS,
    QA_GRV,
    AZ_TILD,
    HOMEQA_GRV,
    HOMEAZ_TILD,
#endif
#if defined(ARTSEY_ENABLE) && !defined(NO_ACTION_ONESHOT)
    ARTSEY_B,
    ARTSEY_C,
    ARTSEY_D,
    ARTSEY_F,
    ARTSEY_G,
    ARTSEY_H,
    ARTSEY_J,
    ARTSEY_K,
    ARTSEY_L,
    ARTSEY_M,
    ARTSEY_P,
    ARTSEY_Q,
    ARTSEY_U,
    ARTSEY_V,
    ARTSEY_W,
    ARTSEY_X,
    ARTSEY_Z,
    ARTSEY_BSPC,
    ARTSEY_DEL,
    ARTSEY_TAB,
    ARTSEY_SPC,
    ARTSEY_ENT,
    ARTSEY_LCTRL,
    ARTSEY_LGUI,
    ARTSEY_LALT,
    ARTSEY_ESC,
    ARTSEY_LSFT,
    ARTSEY_CAPS,
    ARTSEY_COMM,
    ARTSEY_DOT,
    ARTSEY_SLSH,
    ARTSEY_QUOT,
    ARTSEY_DQUO,
    ARTSEY_QUES,
    ARTSEY_SCLN,
    ARTSEY_COLN,
    ARTSEY_EXLM,
    COMBO_LENGTH
#endif
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM W_E_COMBO[]      = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM X_C_COMBO[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM I_O_COMBO[]      = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM COMM_DOT_COMBO[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM LEADER_COMBO[]   = {SYM, NAV, COMBO_END};
const uint16_t PROGMEM email_combo[]    = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM DOT_SLASH_COMBO[]  = {KC_DOT,   KC_SLSH, COMBO_END};

#ifdef STENO_LITE_ENABLE
const uint16_t PROGMEM ENT_E_V_COMBO[] = {KC_ENT, KC_E, KC_V, COMBO_END};
const uint16_t PROGMEM ENT_U_COMBO[]   = {KC_ENT, KC_U, COMBO_END};
const uint16_t PROGMEM ENT_A_COMBO[]   = {KC_ENT, KC_A, COMBO_END};
const uint16_t PROGMEM ENT_W_COMBO[]   = {KC_ENT, KC_W, COMBO_END};
const uint16_t PROGMEM ENT_F_COMBO[]   = {KC_ENT, KC_F, COMBO_END};
const uint16_t PROGMEM ENT_H_COMBO[]   = {KC_ENT, KC_H, COMBO_END};
const uint16_t PROGMEM ENT_T_COMBO[]   = {KC_ENT, KC_T, COMBO_END};
const uint16_t PROGMEM ENT_M_COMBO[]   = {KC_ENT, KC_M, COMBO_END};
const uint16_t PROGMEM ENT_G_COMBO[]   = {KC_ENT, KC_G, COMBO_END};
const uint16_t PROGMEM ENT_O_COMBO[]   = {KC_ENT, KC_O, COMBO_END};
const uint16_t PROGMEM ENT_O_L_COMBO[] = {KC_ENT, KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM ENT_I_COMBO[]   = {KC_ENT, KC_I, COMBO_END};
const uint16_t PROGMEM ENT_I_S_COMBO[] = {KC_ENT, KC_I, KC_S, COMBO_END};
const uint16_t PROGMEM ENT_T_A_COMBO[] = {KC_ENT, KC_T, KC_A, COMBO_END};
const uint16_t PROGMEM ENT_K_COMBO[]   = {KC_ENT, KC_K, COMBO_END};
const uint16_t PROGMEM ENT_T_S_COMBO[] = {KC_ENT, KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM ENT_D_N_COMBO[] = {KC_ENT, KC_D, KC_N, COMBO_END};
const uint16_t PROGMEM ENT_I_T_COMBO[] = {KC_ENT, KC_I, KC_T, COMBO_END};
const uint16_t PROGMEM H_V_COMBO[]     = {KC_H, KC_V, COMBO_END};
const uint16_t PROGMEM Q_K_COMBO[]     = {KC_Q, KC_K, COMBO_END};
const uint16_t PROGMEM K_B_COMBO[]     = {KC_K, KC_B, COMBO_END};
const uint16_t PROGMEM W_A_COMBO[]     = {KC_W, KC_A, COMBO_END};
#endif

#ifdef COMBO_SYMBOL_ENABLE
// Right hand side
const uint16_t PROGMEM P_SCLN_COMBO[]     = {KC_P, KC_SCLN, COMBO_END};
const uint16_t PROGMEM SCLN_SLASH_COMBO[] = {KC_SCLN, KC_SLASH, COMBO_END};
const uint16_t PROGMEM H_J_COMBO[]        = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM N_M_COMBO[]        = {KC_W, KC_A, COMBO_END};

// Left hand side
const uint16_t PROGMEM Q_A_COMBO[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM A_Z_COMBO[] = {KC_A, KC_Z, COMBO_END};

// Home-row version
const uint16_t PROGMEM Q_GUIA_COMBO[] = {KC_Q, GUI_A, COMBO_END};
const uint16_t PROGMEM GUIA_Z_COMBO[] = {GUI_A, KC_Z, COMBO_END};
#endif

#if defined(ARTSEY_ENABLE) && !defined(NO_ACTION_ONESHOT)
// Custom ARTSEY version with colemak https://github.com/purple-rw/artsey-keyboard
// Letters
const uint16_t PROGMEM ARTSEY_B_COMBO[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_C_COMBO[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_D_COMBO[] = {KC_I, KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_F_COMBO[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_G_COMBO[] = {KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM ARTSEY_H_COMBO[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_J_COMBO[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM ARTSEY_K_COMBO[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM ARTSEY_L_COMBO[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_M_COMBO[] = {KC_A, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM ARTSEY_P_COMBO[] = {KC_A, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_Q_COMBO[] = {KC_O, KC_I, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_U_COMBO[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM ARTSEY_V_COMBO[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ARTSEY_W_COMBO[] = {KC_O, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_X_COMBO[] = {KC_O, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM ARTSEY_Z_COMBO[] = {KC_O, KC_I, KC_E, KC_N, COMBO_END};
// Control
const uint16_t PROGMEM ARTSEY_BSPC_COMBO[] = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_DEL_COMBO[]  = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ARTSEY_TAB_COMBO[]  = {KC_I, KC_E, KC_N, KC_A, COMBO_END};
const uint16_t PROGMEM ARTSEY_SPC_COMBO[]  = {KC_A, KC_R, KC_S, KC_T, COMBO_END};
// Mods
const uint16_t PROGMEM ARTSEY_ENT_COMBO[]   = {KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_LCTRL_COMBO[] = {KC_O, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_LGUI_COMBO[]  = {KC_O, KC_S, COMBO_END};
const uint16_t PROGMEM ARTSEY_LALT_COMBO[]  = {KC_O, KC_R, COMBO_END};
const uint16_t PROGMEM ARTSEY_ESC_COMBO[]   = {KC_E, KC_N, KC_A, COMBO_END};
const uint16_t PROGMEM ARTSEY_LSFT_COMBO[]  = {KC_O, KC_I, KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM ARTSEY_CAPS_COMBO[]  = {KC_A, KC_R, KC_S, KC_N, COMBO_END};
// Symbols
const uint16_t PROGMEM ARTSEY_COMM_COMBO[] = {KC_S, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_DOT_COMBO[]  = {KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_SLSH_COMBO[] = {KC_A, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_QUOT_COMBO[] = {KC_R, KC_S, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_DQUO_COMBO[] = {KC_A, KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM ARTSEY_QUES_COMBO[] = {KC_I, KC_N, KC_A, COMBO_END};
const uint16_t PROGMEM ARTSEY_SCLN_COMBO[] = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM ARTSEY_COLN_COMBO[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM ARTSEY_EXLM_COMBO[] = {KC_I, KC_R, COMBO_END};
#endif

combo_t key_combos[] = {
    // Controls
    [WE_ESC]      = COMBO(W_E_COMBO, KC_ESC),
    [XC_TAB]      = COMBO(X_C_COMBO, KC_TAB),
    [IO_BSPC]     = COMBO(I_O_COMBO, KC_BSPC),
    [COMMDOT_DEL] = COMBO(COMM_DOT_COMBO, KC_DEL),
    [LEADER]      = COMBO(LEADER_COMBO, QK_LEAD),
    [EM_EMAIL]    = COMBO_ACTION(email_combo),
    [DOTSLASH_UPDIR]  = COMBO_ACTION(DOT_SLASH_COMBO),
#ifdef STENO_LITE_ENABLE
    [ENTEV_EVERY]  = COMBO_ACTION(ENT_E_V_COMBO),
    [ENTU_YOU]     = COMBO_ACTION(ENT_U_COMBO),
    [ENTA_AND]     = COMBO_ACTION(ENT_A_COMBO),
    [ENTW_WITH]    = COMBO_ACTION(ENT_W_COMBO),
    [ENTF_FOR]     = COMBO_ACTION(ENT_F_COMBO),
    [ENTH_HERE]    = COMBO_ACTION(ENT_H_COMBO),
    [ENTT_THE]     = COMBO_ACTION(ENT_T_COMBO),
    [ENTM_MENT]    = COMBO_ACTION(ENT_M_COMBO),
    [ENTG_ING]     = COMBO_ACTION(ENT_G_COMBO),
    [ENTO_OUGH]    = COMBO_ACTION(ENT_O_COMBO),
    [ENTOL_OULD]   = COMBO_ACTION(ENT_O_L_COMBO),
    [ENTI_ION]     = COMBO_ACTION(ENT_I_COMBO),
    [ENTIS_IONS]   = COMBO_ACTION(ENT_I_S_COMBO),
    [ENTTA_THAT]   = COMBO_ACTION(ENT_T_A_COMBO),
    [ENTK_KEY]     = COMBO_ACTION(ENT_K_COMBO),
    [ENTTS_THIS]   = COMBO_ACTION(ENT_T_S_COMBO),
    [ENTDN_DONT]   = COMBO_ACTION(ENT_D_N_COMBO),
    [ENTIT_IN_THE] = COMBO_ACTION(ENT_I_T_COMBO),
    [HV_HAVE]      = COMBO_ACTION(H_V_COMBO),
    [QK_QMK]       = COMBO_ACTION(Q_K_COMBO),
    [KB_KEYBOARD]  = COMBO_ACTION(K_B_COMBO),
    [WA_WHAT]      = COMBO_ACTION(W_A_COMBO),
#endif
#ifdef COMBO_SYMBOL_ENABLE
    // Right hand side
    [PSCLN_BSLS]     = COMBO(P_SCLN_COMBO, KC_BSLS),
    [SCLNSLASH_PIPE] = COMBO(SCLN_SLASH_COMBO, KC_PIPE),
    [HJ_MINS]        = COMBO(H_J_COMBO, KC_MINS),
    [NM_UNDS]        = COMBO(N_M_COMBO, KC_UNDS),
    // Left hand side
    [QA_GRV]  = COMBO(Q_A_COMBO, KC_GRV),
    [AZ_TILD] = COMBO(A_Z_COMBO, KC_TILD),
    // Home-row version
    [HOMEQA_GRV]  = COMBO(Q_GUIA_COMBO, KC_GRV),
    [HOMEAZ_TILD] = COMBO(GUIA_Z_COMBO, KC_TILD),
#endif
#if defined(ARTSEY_ENABLE) && !defined(NO_ACTION_ONESHOT)
    // Letters
    [ARTSEY_B] = COMBO(ARTSEY_B_COMBO, KC_B),
    [ARTSEY_C] = COMBO(ARTSEY_C_COMBO, KC_C),
    [ARTSEY_D] = COMBO(ARTSEY_D_COMBO, KC_D),
    [ARTSEY_F] = COMBO(ARTSEY_F_COMBO, KC_F),
    [ARTSEY_G] = COMBO(ARTSEY_G_COMBO, KC_G),
    [ARTSEY_H] = COMBO(ARTSEY_H_COMBO, KC_H),
    [ARTSEY_J] = COMBO(ARTSEY_J_COMBO, KC_J),
    [ARTSEY_K] = COMBO(ARTSEY_K_COMBO, KC_K),
    [ARTSEY_L] = COMBO(ARTSEY_L_COMBO, KC_L),
    [ARTSEY_M] = COMBO(ARTSEY_M_COMBO, KC_M),
    [ARTSEY_P] = COMBO(ARTSEY_P_COMBO, KC_P),
    [ARTSEY_Q] = COMBO(ARTSEY_Q_COMBO, KC_Q),
    [ARTSEY_U] = COMBO(ARTSEY_U_COMBO, KC_U),
    [ARTSEY_V] = COMBO(ARTSEY_V_COMBO, KC_V),
    [ARTSEY_W] = COMBO(ARTSEY_W_COMBO, KC_W),
    [ARTSEY_X] = COMBO(ARTSEY_X_COMBO, KC_X),
    [ARTSEY_Z] = COMBO(ARTSEY_Z_COMBO, KC_Z),
    // Control
    [ARTSEY_BSPC] = COMBO(ARTSEY_BSPC_COMBO, KC_BSPC),
    [ARTSEY_DEL]  = COMBO(ARTSEY_DEL_COMBO, KC_DEL),
    [ARTSEY_TAB]  = COMBO(ARTSEY_TAB_COMBO, KC_TAB),
    [ARTSEY_SPC]  = COMBO(ARTSEY_SPC_COMBO, KC_SPC),
    // Mods
    [ARTSEY_ENT]   = COMBO(ARTSEY_ENT_COMBO, KC_ENT),
    [ARTSEY_LCTRL] = COMBO(ARTSEY_LCTRL_COMBO, OS_LCTL),
    [ARTSEY_LGUI]  = COMBO(ARTSEY_LGUI_COMBO, OS_LGUI),
    [ARTSEY_LALT]  = COMBO(ARTSEY_LALT_COMBO, OS_LALT),
    [ARTSEY_ESC]   = COMBO(ARTSEY_ESC_COMBO, KC_ESC),
    [ARTSEY_LSFT]  = COMBO(ARTSEY_LSFT_COMBO, OS_LSFT),
    [ARTSEY_CAPS]  = COMBO(ARTSEY_CAPS_COMBO, KC_CAPS),
    // Symbols
    [ARTSEY_COMM] = COMBO(ARTSEY_COMM_COMBO, KC_COMM),
    [ARTSEY_DOT]  = COMBO(ARTSEY_DOT_COMBO, KC_DOT),
    [ARTSEY_SLSH] = COMBO(ARTSEY_SLSH_COMBO, KC_SLSH),
    [ARTSEY_QUOT] = COMBO(ARTSEY_QUOT_COMBO, KC_QUOT),
    [ARTSEY_DQUO] = COMBO(ARTSEY_DQUO_COMBO, KC_DQUO),
    [ARTSEY_QUES] = COMBO(ARTSEY_QUES_COMBO, KC_QUES),
    [ARTSEY_SCLN] = COMBO(ARTSEY_SCLN_COMBO, KC_SCLN),
    [ARTSEY_COLN] = COMBO(ARTSEY_COLN_COMBO, KC_COLN),
    [ARTSEY_EXLM] = COMBO(ARTSEY_EXLM_COMBO, KC_EXLM),
#endif
};

void process_combo_event(uint16_t combo_index, bool pressed) {
#ifdef CONSOLE_ENABLE
    combo_t *combo = &key_combos[combo_index];
    uint8_t idx = 0;
    uint16_t combo_keycode;
    while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        uprintf("0x%04X,%u,%u,%u,%u,0x%02X,0x%02X,0\n",
            combo_keycode,
            KEYLOC_COMBO,
            KEYLOC_COMBO,
            get_highest_layer(layer_state),
            pressed,
            get_mods(),
            get_oneshot_mods()
            /* tap_count */
        );
        idx++;
    }
#endif
    switch (combo_index) {
        case EM_EMAIL:
            if (pressed) {
                SEND_STRING("ronnyvu321@gmail.com");
            }
            break;
#ifdef STENO_LITE_ENABLE
        case ENTEV_EVERY:
            if (pressed) {
                SEND_STRING("every");
            }
            break;
        case ENTU_YOU:
            if (pressed) {
                SEND_STRING("you");
            }
            break;
        case ENTA_AND:
            if (pressed) {
                SEND_STRING("and");
            }
            break;
        case ENTW_WITH:
            if (pressed) {
                SEND_STRING("with");
            }
            break;
        case ENTF_FOR:
            if (pressed) {
                SEND_STRING("for");
            }
            break;
        case ENTH_HERE:
            if (pressed) {
                SEND_STRING("here");
            }
            break;
        case ENTT_THE:
            if (pressed) {
                SEND_STRING("the");
            }
            break;
        case ENTM_MENT:
            if (pressed) {
                SEND_STRING("ment");
            }
            break;
        case ENTG_ING:
            if (pressed) {
                SEND_STRING("ing");
            }
            break;
        case ENTO_OUGH:
            if (pressed) {
                SEND_STRING("ough");
            }
            break;
        case ENTOL_OULD:
            if (pressed) {
                SEND_STRING("ould");
            }
            break;
        case ENTI_ION:
            if (pressed) {
                SEND_STRING("ion");
            }
            break;
        case ENTIS_IONS:
            if (pressed) {
                SEND_STRING("ions");
            }
            break;
        case ENTTA_THAT:
            if (pressed) {
                SEND_STRING("that");
            }
            break;
        case ENTK_KEY:
            if (pressed) {
                SEND_STRING("key");
            }
            break;
        case KB_KEYBOARD:
            if (pressed) {
                SEND_STRING("keyboard");
            }
            break;
        case WA_WHAT:
            if (pressed) {
                SEND_STRING("what");
            }
            break;
        case ENTTS_THIS:
            if (pressed) {
                SEND_STRING("this");
            }
            break;
        case ENTDN_DONT:
            if (pressed) {
                SEND_STRING("don't");
            }
            break;
        case ENTIT_IN_THE:
            if (pressed) {
                SEND_STRING("in the");
            }
            break;
#endif
        case DOTSLASH_UPDIR:
            if (pressed) {
                SEND_STRING("../");
            }
        break;
    }
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Enable ARTSEY combos on layer `_ARTSEY` */
    switch (combo_index) {
#if defined(ARTSEY_ENABLE) && !defined(NO_ACTION_ONESHOT)
        case ARTSEY_B ... ARTSEY_EXLM:
            return layer_state_is(_ARTSEY);
#endif
    }
    return true;
}
//clang-format on
