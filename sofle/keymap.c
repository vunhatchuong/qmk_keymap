/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#include QMK_KEYBOARD_H
#include "ronny.h"
#include "encoder.c"

extern uint32_t oled_timer;

enum sofle_layers {
    _SYMS,
    _FUNC,
    _NAV,
};

enum custom_keycodes { 
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    SNAKECASE,
    TOG_VIM,
    ANDREW_LEADER
};
// Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

// Symbols chart
// ↯ hyper key (ctrl, alt, shift, super)
// ⌘ command
// ⌥ option
// ⌃ control
// ⇧ shift
// ⌫ backspace
// ⌦ delete
// ⎋ escape
// ↩ enter

// clang-format off
#define LAYOUT_sofle_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_TAB, 		________________NUMBER_LEFT________________,                ________________NUMBER_RIGHT_______________,          KC_DEL,   \
    CTL_T(KC_ESC),  K01,     K02,     K03,     K04,     K05,                       K06,     K07,     K08,     K09,     K0A,           KC_BSPC,  \
    KC_LSFT,        K11,     K12,     K13,     K14,     K15,                       K16,     K17,     K18,     K19,     LT(_NAV,K1A),  KC_QUOT,  \
    KC_LCTL,       K21,     K22,     K23,     K24,     K25, KC_MUTE,     KC_MPLY, K26,     K27,     K28,     K29,     K2A,     RSFT_T(KC_ENT),  \
                    KC_LCTL, KC_LALT, KC_LGUI, MO(_SYMS), KC_SPC,        	       KC_ENT, MO(_FUNC), KC_MINS,  C(KC_C), C(KC_V)                \
    )

#define LAYOUT_sofle_base_wrapper(...) LAYOUT_sofle_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  Tab |   1  |   2  |   3  |  4  |   5   |                    |   6  |   7  |   8  |   9  |   0  |  ⌦  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |CTLESC|  Q   |   W  |   E  |   R  |  T   |                    |   Y  |   U  |   I  |   O  |   P  |  ⌫  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   A  |   S  |   D  |   F  |  G   |-------.    ,-------|   H  |   J  |   K  |   L  | CUM_;|  '   |
     * |------+------+------+------+------+------| MUTE  |    |  PLAY |------+------+------+------+------+------|
     * |  MEH |   Z  |   X  |   C  |   V  |  B   |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |SFTENT|
     * `----------------------------------------/        /     \      \-----------------------------------------'
     *            | LCTR | LAlt | LGUI |SYMB | / Space  /       \ Enter\  | FUNC |  -  | COPY | PASTE |
     *            |      |      |      |     |/        /         \      \ |      |     |      |       |
     *            `-----------------------------------'           '------''---------------------------'
     */

    [_QWERTY] = LAYOUT_sofle_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK_DH] = LAYOUT_sofle_base_wrapper(
        ________________COLEMAK_DH_L1______________, ________________COLEMAK_DH_R1______________,
        ________________COLEMAK_DH_L2______________, ________________COLEMAK_DH_R2______________,
        ________________COLEMAK_DH_L3______________, ________________COLEMAK_DH_R3______________
    ),

    /* SYMB
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |  4  |   5   |                    |   6  |   7  |   8  |   9  |   0  |  Del |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  ~   |   (  |   )  |   +  |   =  |   <  |                    |   >  |   -  |      |  [   |   ]  |   \  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   {  |   }  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTR | LAlt | LGUI |      | / Space /       \ Enter\  |      |  -  |      |       |
     *            |      |      |      |      |/       /         \      \ |      |     |      |       |
     *            `-----------------------------------'           '------''---------------------------'
     */

    [_SYMS] = LAYOUT_wrapper(
        KC_GRV,    ________________NUMBER_LEFT________________,                     		  ________________NUMBER_RIGHT_______________, 	      KC_DEL,
        KC_TILD,   KC_LPRN,   KC_RPRN,   KC_PLUS,   KC_EQL,  KC_LT,                	  		  KC_GT,    KC_MINS,   XXXXXXX,   KC_LBRC,  KC_RBRC,  KC_BSLS,
        _______,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,  KC_PERC,        		  		  KC_CIRC,  KC_AMPR,   KC_ASTR,   KC_LCBR,  KC_RCBR,  KC_PIPE,
        _______,  ___________________EMPTY___________________, _______,                    _______, ___________________EMPTY___________________,  RSFT_T(KC_ENT),
                        _______,  _______,   _______,   XXXXXXX, _______,       			 _______,   XXXXXXX,   _______,   _______,  _______),

    /* FUNC
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL | XCase|   VIM   |      |      |      |                 | WH_R |  M1  | MS_U |  M2  | WH_U | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------.    ,-------| WH_L | MS_L | MS_D | MS_R | WH_D |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTR | LAlt | LGUI |      | / LEADER /       \ Enter\  |      |  -  |      |       |
     *            |      |      |      |      |/       /         \      \ |      |     |      |       |
     *            `-----------------------------------'           '------''---------------------------'
     */
    [_FUNC] = LAYOUT_wrapper(
        _______,   __________________FUNC_L1__________________,                          __________________FUNC_R1__________________,  KC_F11,
        KC_LCTL,  ___________________EMPTY___________________,                     	 _________________MOUSE_NAV_________________,  KC_F12,
        _______,   ___________________EMPTY___________________,                     	 ________________MOUSE_WHEEL________________,  XXXXXXX,
        _______,   ___________________EMPTY___________________, _______,       _______,  _________________MOUSE_BTN_________________,  RSFT_T(KC_ENT),
                   _______, _______, _______, XXXXXXX, _______,                       _______,  XXXXXXX, _______, _______, _______),
    /* CUM
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |  F13 |  F14 |  F15 |  F16 |  F17 |                    |  F18 |  F19 |  F20 |  F21 |  F22 | F23  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |      |      |      |      |      |                    |      |      |      |      |      | F24  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTR | LAlt | LGUI |      | /Space  /       \Enter \  |      |  -  |      |       |
     *            |      |      |      |      |/       /         \      \ |      |     |      |       |
     *            `-----------------------------------'           '------''---------------------------'
     */
    [_NAV] = LAYOUT_wrapper(
        _______,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,                      KC_F18,   KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,
        KC_LCTL,  ___________________EMPTY___________________,                      	___________________EMPTY___________________,  KC_F24,
        _______,   _______,  _______,  _______,  _______,  KC_CAPS,                     ____________________NAV____________________,  XXXXXXX,
        _______,   ___________________EMPTY___________________, _______,       _______, ___________________EMPTY___________________,  RSFT_T(KC_ENT),
                   _______, _______, _______,  XXXXXXX,  _______,       		   _______,   XXXXXXX,  _______,  _______,  _______)
};
// clang-formatter on

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
            return NULL; // signal that we're done
        default:
            return NULL;
    }
}
#endif

void oled_timer_reset(void) {
    oled_timer = timer_read32();
}
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

    if (record->event.pressed) oled_timer_reset();
    switch (keycode) {
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
    }
    return true;
}
