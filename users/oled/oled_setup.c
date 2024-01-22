#include "quantum.h"
#include "ronny.h"

uint32_t oled_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270; // flips the display 180 degrees if offhand
    }
    return OLED_ROTATION_270;
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWER"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CLMK"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Syms"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Func"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

void render_wpm(void) {
#ifdef WPM_ENABLE
    oled_write_P(PSTR("   WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
#endif
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (timer_elapsed32(oled_timer) > 120000) { // turn off after 3min
            oled_off();
            return false;
        } else {
            print_status_narrow();
            render_wpm();
#ifdef LUNA_ENABLE
            led_usb_state = host_keyboard_led_state();
            render_luna(0, 13);
#endif
        }

    } else {
#ifdef OCEAN_DREAM_ENABLE
        render_stars();
#endif
    }
    return false;
}
