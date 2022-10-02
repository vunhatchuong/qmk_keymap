/*
 * Copyright QMK Community
 * Copyright 2021 Tyler Thrailkill (@snowe/@snowe2010) <tyler.b.thrailkill@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef OLED_ENABLE

#    include QMK_KEYBOARD_H
#    include "quantum.h"
#    include "snowe.h"

#    include <stdio.h> // for keylog?
uint32_t        oled_timer = 0;
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270; // flips the display 180 degrees if offhand
    }
    return OLED_ROTATION_270;
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Main"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Syms"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Func"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("CUM"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

// void render_bootmagic_status(bool status) {
//    /* Show Ctrl-Gui Swap options */
//    static const char PROGMEM logo[][2][3] = {
//        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//    };
//    if (status) {
//        oled_write_ln_P(logo[0][0], false);
//        oled_write_ln_P(logo[0][1], false);
//    } else {
//        oled_write_ln_P(logo[1][0], false);
//        oled_write_ln_P(logo[1][1], false);
//    }
//}
void render_bootmagic_status(void) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    // oled_write_P(PSTR("BTMGK"), false);
    // oled_write_P(PSTR(""), false);
    if (!keymap_config.swap_lctl_lgui) {
        oled_write_P(logo[1][0], false);
        oled_write_P(PSTR("   "), false);
        oled_write_P(logo[1][1], false);
    } else {
        oled_write_P(logo[0][0], false);
        oled_write_P(PSTR("   "), false);
        oled_write_P(logo[0][1], false);
    }
    // oled_write_P(PSTR("   NKRO "), keymap_config.nkro);
    oled_write_P(PSTR("   WPM: "), false);

    char wpm[6];
    itoa(get_current_wpm(), wpm, 10);
    oled_write_ln(wpm, false);
}

// void render_custom_func(void) {
//     static const char PROGMEM snake_logo[] = {// 'python_20px', 20x20px
//                                               0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xbc, 0xbe, 0xb6, 0xbe, 0xbe, 0xfe, 0xfe, 0xfc, 0x00, 0xe0, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x07, 0xf3, 0xf9, 0xfd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdc, 0x1e, 0x1f, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//     oled_write_P(PSTR("STATE"), false);
//     if (is_caps_word_on()) {
//         oled_write_P(PSTR("SHOUT"), false);
//     } else {
//         oled_write_P(PSTR("     "), false);
//     }
//     if (get_xcase_state() == XCASE_ON) {
//         oled_write_raw_P(snake_logo, sizeof(snake_logo));
//     } else {
//         oled_write_P(PSTR(" "), false);
//     }
// }
void display_features(void) {
#    ifdef LEADER_DISPLAY_STR
    static uint16_t timer = 0;
    if (is_leading()) {
        oled_write_ln(leader_display_str(), false);
        timer = timer_read();
    } else if (vim_mode_enabled()) {
        switch (get_vim_mode()) {
            case NORMAL_MODE:
                oled_write_P(PSTR("NORM\n"), false);
                break;
            case INSERT_MODE:
                oled_write_P(PSTR("INSRT\n"), false);
                break;
            case VISUAL_MODE:
                oled_write_P(PSTR("VISUL\n"), false);
                break;
            case VISUAL_LINE_MODE:
                oled_write_P(PSTR("VISLL\n"), false);
                break;
            default:
                oled_write_P(PSTR("?????\n"), false);
                break;
        }
    } else if (timer_elapsed(timer) < 175) {
        oled_write_ln(leader_display_str(), false);
    } else {
        timer = timer_read() - 200; // prevent it from ever looping around
        oled_write_ln("", false);
    }
#    endif
}
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (timer_elapsed32(oled_timer) > 120000) { // turn off after 3min
            oled_off();
            return false;
        } else {
            print_status_narrow();
            oled_render_keylog();
            render_bootmagic_status();
            display_features();
            // render_custom_func();

#    ifdef LUNA_ENABLE
            led_usb_state = host_keyboard_led_state();
            render_luna(0, 13);
#    endif
        }

    } else {
#    ifdef OCEAN_DREAM_ENABLE
        render_stars();
#    endif
    }
    return false;
}

#endif // OLED_ENABLE
