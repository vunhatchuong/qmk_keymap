#include "ronny.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// clang-format off
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X\t%u\t%u\t0x%X\t%u\t0x%02X\t0x%02X\t%u\n", keycode, is_combo ? 254 : record->event.key.row, is_combo ? 254 : record->event.key.col, layer_state | default_layer_state, record->event.pressed, get_mods(), get_oneshot_mods(), record->tap.count);
#endif
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

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYM, _FUNC, _ADJUST) | update_tri_layer_state(state, _SYM, _NAV, _ADJUST);
    return state;
}
