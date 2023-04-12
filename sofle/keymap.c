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

// Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

// clang-format off
#define LAYOUT_sofle_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_TAB,    ________________NUMBER_LEFT________________,               ________________NUMBER_RIGHT_______________,              KC_DEL,   \
    CTL_ESC,   K01,     K02,     K03,     K04,     K05,                       K06,     K07,     K08,     K09,     K0A,             KC_BSPC,   \
    KC_LSFT,   K11,     K12,     K13,     K14,     K15,                       K16,     K17,     K18,     K19,     K1A,             KC_QUOT,   \
    KC_LCTL,   K21,     K22,     K23,     K24,     K25, KC_MUTE,     KC_MPLY, K26,     K27,     K28,     K29,     K2A,       RSFT_T(KC_ENT),  \
               KC_LCTL, KC_LALT, KC_LGUI, SYM,     KC_SPC,                 KC_ENT,     NAV, KC_MINS,    COPY,   PASTE                         \
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

    [_COLEMAKDH] = LAYOUT_sofle_base_wrapper(
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

    [_SYM] = LAYOUT_wrapper(
        KC_F12,    __________________FUNC_L1__________________,                               __________________FUNC_R1__________________,        KC_F11,
        KC_GRV,    ________________NUMBER_LEFT________________,                               ________________NUMBER_RIGHT_______________,        KC_BSPC,
        KC_TILD,   O_PRQOT,   KC_LBRC,   KC_LCBR,   KC_LPRN, KC_EQL,                          KC_PLUS,  KC_RPRN,   KC_RCBR,   KC_RBRC,  C_PRQOT,  KC_BSLS,
        _______,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,  KC_PERC,  _______,     _______,  KC_CIRC,  KC_AMPR,   KC_ASTR,   O_BRQOT,  C_BRQOT,  KC_PIPE,
                        _______,  _______,   _______,   XXXXXXX, _______,                    _______,   XXXXXXX,   _______,   _______,  _______
    ),

    /* NAV
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
        KC_F12,    __________________FUNC_L1__________________,                         __________________FUNC_R1__________________,  KC_F11,
        KC_LCTL,   ___________________EMPTY___________________,                         _________________MOUSE_NAV_________________,  KC_WH_L,
        _______,   _______,  _______,  _______,  _______,  KC_CAPS,                     ___________________ARROW___________________,  KC_WH_R,
        _______,   ___________________EMPTY___________________, _______,       _______, _________________VIM_ARROW_________________,  RSFT_T(KC_ENT),
                   _______, _______, _______,  XXXXXXX,  _______,                  _______,   XXXXXXX,  _______,  _______,  _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        TD_BOOT,   TD_QWERTY, TD_COLEMAKDH, TD_GAMING, XXXXXXX, XXXXXXX,                ___________________EMPTY___________________,  XXXXXXX,
        _______,   ___________________EMPTY___________________,                         ___________________EMPTY___________________,  XXXXXXX,
        _______,   _______,  _______,  _______,  _______,  KC_CAPS,                     ___________________ARROW___________________,  XXXXXXX,
        _______,   ___________________EMPTY___________________, _______,       _______, _________________ADJUST_R3_________________,  _______,
                   _______, _______, _______,  XXXXXXX,  _______,                  _______,   XXXXXXX,  _______,  _______,  _______
    )
};
// clang-formatter on
