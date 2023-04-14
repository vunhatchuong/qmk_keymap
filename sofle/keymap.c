#include QMK_KEYBOARD_H
#include "ronny.h"
#include "g/keymap_combo.h"

// clang-format off
#define LAYOUT_sofle_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_TAB,   ________________NUMBER_LEFT________________,               ________________NUMBER_RIGHT_______________,       KC_DEL,         \
    CTL_ESC,  K01,      K02,      K03,      K04,      K05,                       K06,     K07,     K08,     K09,     K0A,   KC_BSPC,        \
    KC_LSFT,  K11,      K12,      K13,      K14,      K15,                       K16,     K17,     K18,     K19,     K1A,   KC_QUOT,        \
    KC_LCTL,  K21,      K22,      K23,      K24,      K25, KC_MUTE,     KC_MPLY, K26,     K27,     K28,     K29,     K2A,   RSFT_T(KC_ENT), \
              KC_LCTL,  KC_LALT,  KC_LGUI,  SYM,      SH_T(KC_SPC),              KC_ENT,  NAV,     KC_MINS, COPY,    PASTE                  \
    )

#define LAYOUT_sofle_base_wrapper(...) LAYOUT_sofle_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ,-----------------------------------------.                    ,-----------------------------------------.
    * | TAB  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |DEL⌦ |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |ESC/⎈ |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   |BSPC⌫|
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LSFT ⇧|  A   |  S   |  D   |  F   |  G   |,------.    ,------.|  H   |  J   |  K   |  L   | : ;  | ' "  |
    * |------+------+------+------+------+------|| MUTE |    |  ⏯   ||------+------+------+------+------+------|
    * |LCTL ⎈|  Z   |  X   |  C   |  V   |  B   |`------'    `------'|  N   |  M   | , <  | . >  |SLASH |SFTENT|
    * `-------------+------+------+------+-.------------.     ,------------.-+------+------+------+-------------'
    *               |LCTL ⎈|LALT⎇|LGUI◆|/ SYM   / SPC  /     \ ENT  \ NAV  \| - _  | ⧉   |  📋  |
    *               |      |      |      /      /      /      \      \      \      |      |      |
    *               `---------------------------------'        `---------------------------------'
    *                                                                                   generated by [keymapviz] */

    [_QWERTY] = LAYOUT_sofle_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    /* ,-----------------------------------------.                    ,-----------------------------------------.
    * | TAB  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |DEL⌦ |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |ESC/⎈ |  Q   |  W   |  F   |  P   |  B   |                    |  J   |  L   |  U   |  Y   | : ;  |BSPC⌫|
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LSFT ⇧|  A   |  R   |  S   |  T   |  G   |,------.    ,------.|  M   |  N   |  E   |  I   |  O   | ' "  |
    * |------+------+------+------+------+------|| MUTE |    |  ⏯   ||------+------+------+------+------+------|
    * |LCTL ⎈|  Z   |  X   |  C   |  D   |  V   |`------'    `------'|  K   |  H   | , <  | . >  |SLASH |SFTENT|
    * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
    *               |LCTL ⎈|LALT⎇|LGUI◆|/ SYM   / SPC  /     \ ENT  \ NAV  \| - _  | ⧉   |  📋  |
    *               |      |      |      /      /      /      \      \      \      |      |      |
    *               `---------------------------------'        `---------------------------------'
    *                                                                                   generated by [keymapviz] */

    [_COLEMAKDH] = LAYOUT_sofle_base_wrapper(
        ________________COLEMAK_DH_L1______________, ________________COLEMAK_DH_R1______________,
        ________________COLEMAK_DH_L2______________, ________________COLEMAK_DH_R2______________,
        ________________COLEMAK_DH_L3______________, ________________COLEMAK_DH_R3______________
    ),

    /* ,-----------------------------------------.                    ,-----------------------------------------.
    * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  `   |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |BSPC⌫|
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  ~   |("   |  [   |  {   |  (   |  =   |,------.    ,------.|  +    |  )   |  }   |  ]   |   ")  | \ |  |
    * |------+------+------+------+------+------||      |    |      ||------+------+------+------+------+------|
    * |      |  !   |  @   |  #   |  $   |  %   |`------'    `------'|  ^   |  &   |  *   |  ["  |  "]  |  |   |
    * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
    *               |      |      |      |/      /      /    \      \      \|      |      |      |
    *               |      |      |      /      /      /      \      \      \      |      |      |
    *               `---------------------------------'        `---------------------------------'
    *                                                                                   generated by [keymapviz] */

    [_SYM] = LAYOUT_wrapper(
        KC_F12,   __________________FUNC_L1__________________,                           __________________FUNC_R1__________________,  KC_F11,
        KC_GRV,   ________________NUMBER_LEFT________________,                           ________________NUMBER_RIGHT_______________,  KC_BSPC,
        KC_TILD,  _________________SYMBOL_L2_________________,                           _________________SYMBOL_R2_________________,  KC_BSLS,
        _______,  _________________SYMBOL_L3_________________, _______,         _______, _________________SYMBOL_R3_________________,  KC_PIPE,
                  _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______
    ),

    /* ,-----------------------------------------.                    ,-----------------------------------------.
    * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LCTL ⎈|      |      |      |      |      |                    | M_L | M_D  | M_U  | M_R  |       | WH_L |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      | CAPS |,------.    ,------.| LEFT | DOWN |  UP  | RGHT | PGUP | WH_R |
    * |------+------+------+------+------+------||      |    |      ||------+------+------+------+------+------|
    * |      |      |      |      |      |      |`------'    `------'|VIM_B | END  | HOME |VIM_W | PGDN |ET/SFT|
    * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
    *               |      |      |      |/      /      /    \      \      \|      |      |      |
    *               |      |      |      /      /      /      \      \      \      |      |      |
    *               `---------------------------------'        `---------------------------------'
    *                                                                                   generated by [keymapviz] */

    [_NAV] = LAYOUT_wrapper(
        KC_F12,   __________________FUNC_L1__________________,                     __________________FUNC_R1__________________,  KC_F11,
        KC_LCTL,  __________________TAB_NAV__________________,                     _________________MOUSE_NAV_________________,  KC_WH_L,
        _______,  __________________WWW_NAV__________________,                     ___________________ARROW___________________,  KC_WH_R,
        _______,  ___________________EMPTY___________________, _______,   _______, _________________VIM_ARROW_________________,  RSFT_T(KC_ENT),
                  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______
    ),

    /* ,-----------------------------------------.                    ,-----------------------------------------.
    * |TD(BOO|TD(QWE|TD(COL|TD(GAM|      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      | CAPS |,------.    ,------.| LEFT | DOWN |  UP  | RGHT | PGUP |      |
    * |------+------+------+------+------+------||      |    |      ||------+------+------+------+------+------|
    * |      |      |      |      |      |      |`------'    `------'|      |  ⏭   | VOLU | VOLD |  ⏯   |      |
    * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
    *               |      |      |      |/      /      /    \      \      \|      |      |      |
    *               |      |      |      /      /      /      \      \      \      |      |      |
    *               `---------------------------------'        `---------------------------------'
    *                                                                                   generated by [keymapviz] */

    [_ADJUST] = LAYOUT_wrapper(
        _______,  _________________ADJUST_L1_________________,                     ___________________EMPTY___________________,  XXXXXXX,
        _______,  ___________________EMPTY___________________,                     ___________________EMPTY___________________,  XXXXXXX,
        _______,  _________________ADJUST_L2_________________,                     ___________________ARROW___________________,  XXXXXXX,
        _______,  _________________ADJUST_L3_________________, _______,   _______, _________________ADJUST_R3_________________,  _______,
                  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______
    )
};
// clang-formatter on
