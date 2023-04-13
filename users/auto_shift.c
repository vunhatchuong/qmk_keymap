#include "ronny.h"

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QUOT:
        case KC_DQT:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_QUOT:
            if (shifted) {
                SEND_STRING("'''");
            } else {
                SEND_STRING("'");
            }
            break;
        case KC_DQT:
            if (shifted) {
                SEND_STRING("\"\"\"");
            } else {
                SEND_STRING("\"");
            }
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
    }
}
