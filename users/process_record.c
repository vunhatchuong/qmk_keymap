#include "ronny.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) switch (keycode) {
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

            case KC_SPC:
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

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_R: // I like to hold Ctrl+R to redo many changes in Vim
            return 64;
        default:
            return 64;
    }
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYM, _FUNC, _ADJUST) | update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
    return state;
}
