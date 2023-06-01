#include "ronny.h"

extern uint32_t oled_timer;

#ifdef OLED_ENABLE
void oled_timer_reset(void) {
    oled_timer = timer_read32();
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X\t%u\t%u\t0x%X\t%u\t0x%02X\t0x%02X\t%u\n",
         keycode,
         is_combo ? 254 : record->event.key.row,
         is_combo ? 254 : record->event.key.col,
         layer_state|default_layer_state,
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
         );
#endif
#ifdef CASEMODES_ENABLE
    // Process case modes
    if (!process_case_modes(keycode, record)) {
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

#ifdef CASEMODES_ENABLE
        case SNAKECASE:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            return false;
#endif
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
