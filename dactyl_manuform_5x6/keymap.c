#include "ronny.h"
// #include "g/keymap_combo.h"
#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

// clang-format off
#define LAYOUT_dactyl_wrapper(...) LAYOUT_5x6(__VA_ARGS__)
#define LAYOUT_dactyl_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
    ) \
    LAYOUT_dactyl_wrapper( \
        KC_TAB,   ________________NUMBER_LEFT________________,              ________________NUMBER_RIGHT_______________, KC_DEL,         \
        CTL_ESC,  K01,      K02,      K03,      K04,      K05,              K06,     K07,     K08,     K09,     K0A,   _______,        \
        KC_LSFT , K11,      K12,      K13,      K14,      K15,              K16,     K17,     K18,     K19,     K1A,   KC_QUOT,        \
        KC_LCTL,  K21,      K22,      K23,      K24,      K25,              K26,     K27,     K28,     K29,     K2A,   KC_BSLS, \
                            KC_LALT,KC_LGUI,                                               KC_MINS, KC_EQL, \
                                            SYM,     KC_SPC,                  KC_ENT, KC_BSPC,              \
                                            KC_GRV,  _______,                 NAV,    KC_DEL,            \
                                            _______, KC_CAPS,                _______, _______            \
    )

#define LAYOUT_dactyl_base_wrapper(...) LAYOUT_dactyl_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* ,-----------------------------------------.                    ,-----------------------------------------.
    * | TAB  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |DEL⌦  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |ESC/⎈ |  Q   |  W   |  F   |  P   |  B   |                    |  j   |  l   |  u   |  Y   | : ;  |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LSFT ⇧|  A   |  R   |  S   |  T   |  G   |,------.    ,------.|  M   |  N   |  E   |  I   |  O   | ' "  |
    * |------+------+------+------+------+------|| MUTE |    |  ⏯   |------+------+------+------+------+------|
    * |LCTL ⎈|  Z   |  X   |  C   |  D   |  V   |`------'    `------'|  K   |  H   | , <  | . >  |SLASH |SFTENT|
    * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
    *               |LCTL ⎈|LALT⎇|LGUI◆|/ SYM   / SPC  /     \ ENT  \ NAV  \| - _  | ⧉   |  📋  |
    *               |      |      |      /      /      /      \      \      \      |      |      |
    *               `---------------------------------'        `---------------------------------'
    *                                                                                   generated by [keymapviz] */
    [_COLEMAKDH] = LAYOUT_dactyl_base_wrapper(
        ________________COLEMAK_DH_L1______________, ________________COLEMAK_DH_R1______________,
        _____________COLEMAK_DH_HMR_L2_____________, _____________COLEMAK_DH_HMR_R2_____________,
        ________________COLEMAK_DH_L3______________, ________________COLEMAK_DH_R3______________
    ),

    /*                ┌───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┐
    * ┌───────┬───────┤   `   │   "   │  F4   │  F5   │ │   ¨   │   ^   │   È   │   É   ├───────┬──────┐
    * │ UNDO  │ REDO  ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  F10  │ F11  │
    * ├───────┼───────┤   W   │   F   │   P   │   B   │ │   J   │   L   │   U   │   Y   ├───────┼──────┤
    * │   À   │   Q   ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  : ;  │ - _  │
    * ├───────┼───────┤  R/⎇  │  S/⇧  │  T/⎈  │   G   │ │   M   │  N/⎈  │  E/⇧  │  I/⎇  ├───────┼──────┤
    * │  ESC  │  A/◆  ├───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┤  O/◆  │ ' "  │
    * ├───────┼───────┤   X   │   C   │   D   │   V   │ │   K   │   H   │  , <  │  . >  ├───────┼──────┤
    * │   Z   │REPEAT ├───────┼───────┼───────┴───────┘ └───────┴───────┼───────┼───────┤  / ?  │-> => │
    * └───────┴───────┤TG_MIC │   Ç   │                                 │ AltGr │   `   ├───────┴──────┘
    *                 └───────┴───────┘                                 └───────┴───────┘
    *                                 ┏━━━━━━━┳━━━━━━━┓ ┏━━━━━━━┳━━━━━━━┓
    *                                 ┃TAB/NAV┃  SPC  ┃ ┃ BSPC  ┃ ⏎/SYM ┃
    *                                 ┡━━━━━━━╋━━━━━━━┫ ┣━━━━━━━╋━━━━━━━┩
    *                                 │COMPOSE┃1-SHOT⇧┃ ┃1-SHOT⇧┃  UP   │
    *                                 ├───────╄━━━━━━━┩ ┡━━━━━━━╃───────┤
    *                                 │PLOVER │CAPS/MS│ │SWAPHND│ DOWN  │
    *                                 └───────┴───────┘ └───────┴───────┘       generated by [keymapviz] */
    [_QWERTY] = LAYOUT_dactyl_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
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
    [_SYM] = LAYOUT_dactyl_wrapper(
        KC_F12,   __________________FUNC_L1__________________,                    __________________FUNC_R1__________________,  KC_F11,
        KC_GRV,   ________________NUMBER_LEFT________________,                    ________________NUMBER_RIGHT_______________,  KC_BSPC,
        KC_TILD,  _________________SYMBOL_L2_________________,                    _________________SYMBOL_R2_________________,  KC_BSLS,
        _______,  _________________SYMBOL_L3_________________,                    _________________SYMBOL_R3_________________,  KC_PIPE,
                            KC_LALT,KC_LGUI,                                               KC_PLUS, KC_EQL,
                                            KC_ESC,KC_SPC,                  KC_BSPC, KC_ENT,
                                            KC_TAB,KC_HOME,                 KC_END,  KC_DEL,
                                            KC_BSPC, KC_GRV,                KC_LGUI, KC_LALT
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
    [_NAV] = LAYOUT_dactyl_wrapper(
        KC_F12,   __________________FUNC_L1__________________,                    __________________FUNC_R1__________________,  KC_F11,
        KC_LCTL,  __________________TAB_NAV__________________,                    _________________VIM_ARROW_________________,  KC_WH_L,
        _______,  __________________WWW_NAV__________________,                    ___________________ARROW___________________,  KC_WH_R,
        _______,  ________________MOUSE_WHEEL________________,                    _________________MOUSE_NAV_________________,  RSFT_T(KC_ENT),
                            KC_LALT,KC_LGUI,                                               KC_BTN1, KC_BTN2,
                                            KC_ESC,KC_SPC,                  KC_BSPC, KC_ENT,
                                            KC_TAB,KC_HOME,                 KC_END,  KC_DEL,
                                            KC_BSPC, KC_GRV,                KC_LGUI, KC_LALT
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
    [_ADJUST] = LAYOUT_dactyl_wrapper(
        _______,  _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,  XXXXXXX,
        _______,  ___________________EMPTY___________________,                    _________________ADJUST_R2_________________,  XXXXXXX,
        _______,  _________________ADJUST_L2_________________,                    ___________________ARROW___________________,  XXXXXXX,
        _______,  _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________,  _______,
                            KC_LALT,KC_LGUI,                                               KC_PLUS, KC_EQL,
                                            KC_ESC,KC_SPC,                  KC_BSPC, KC_ENT,
                                            KC_TAB,KC_HOME,                 KC_END,  KC_DEL,
                                            KC_BSPC, KC_GRV,                KC_LGUI, KC_LALT
    )
};
// clang-format on
