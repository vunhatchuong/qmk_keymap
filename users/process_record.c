#include "ronny.h"

extern uint32_t oled_timer;

#ifdef ANDREW_LEADER_ENABLE
// void *leader_layers_app(uint16_t keycode) {
//     switch (keycode) {
//         case KC_F:
//             tap_code16(KC_F20);
//             break;
//         case KC_W:
//             tap_code16(KC_F14);
//             break;
//         case KC_C:
//             tap_code16(KC_F23);
//             break;
//         default:
//             break;
//     }
//     return NULL; // this function is always an endpoint
// }
void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_W:
            tap_code(KC_F14);
            return NULL;
        case KC_F:
            tap_code(KC_F20);
            return NULL;
        case KC_C:
            tap_code(KC_F23);
            return NULL;
        // case KC_A:
        //     return leader_layers_app; // app launcher func
        case KC_V:
            toggle_vim_mode();
            return NULL;
        case KC_R:
            reset_keyboard(); // here LDR r will reset the keyboard
            return NULL;      // signal that we're done
        default:
            return NULL;
    }
}
#endif

#ifdef OLED_ENABLE
void oled_timer_reset(void) {
    oled_timer = timer_read32();
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef ANDREW_LEADER_ENABLE
    // Process leader key sequences MUST BE AT THE TOP
    if (!process_leader(keycode, record)) {
        return false;
    }
#endif

#ifdef XCASE_ENABLE
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
#endif

#ifdef QMK_VIM_ENABLE
    // Process case modes
    if (!process_vim_mode(keycode, record)) {
        return false;
    }
#endif

    if (record->event.pressed)
#ifdef OLED_ENABLE
        oled_timer_reset();
#endif
    switch (keycode) {
        case O_BRQOT:
            if (record->event.pressed) {
                tap_code(KC_LEFT_BRACKET);
                tap_code16(KC_DOUBLE_QUOTE);
            }
            return false;
        case C_BRQOT:
            if (record->event.pressed) {
                tap_code16(KC_DOUBLE_QUOTE);
                tap_code(KC_RIGHT_BRACKET);
            }
            return false;
        case O_PRQOT:
            if (record->event.pressed) {
                tap_code16(KC_LEFT_PAREN);
                tap_code16(KC_DOUBLE_QUOTE);
            }
            return false;
        case C_PRQOT:
            if (record->event.pressed) {
                tap_code16(KC_DOUBLE_QUOTE);
                tap_code16(KC_RIGHT_PAREN);
            }
            return false;

#ifdef ANDREW_LEADER_ENABLE
        case ANDREW_LEADER:
            if (record->event.pressed) {
                start_leading();
            }
            return false;
#endif
#ifdef XCASE_ENABLE
        case SNAKECASE:
            if (record->event.pressed) {
                enable_xcase();
            }
            return false;
#endif
            // #ifdef QMK_VIM_ENABLE
            //         case TOG_VIM:
            //             if(record->event.pressed){
            //                 toggle_vim_mode();
            //             }
            //             return false;
            // #endif
        case KC_LCTL:
        case KC_RCTL:
#ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
#endif
#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
#endif
            break;
        case KC_SPC:
#ifdef LUNA_ENABLE
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
#endif
            break;
        case PANIC: {
#ifndef NO_ACTION_ONESHOT
            clear_oneshot_mods();
#endif
            clear_keyboard();
            layer_move(_QWERTY);
#ifdef CAPS_WORD_ENABLE
            caps_word_off();
#endif
            return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYM, _FUNC, _ADJUST) | update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
    return state;
}
