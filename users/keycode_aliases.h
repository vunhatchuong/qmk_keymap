/*
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2021 Tyler Thrailkill <@snowe/@snowe2010>
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

#pragma once

// ---
// Layers
#define QWERTY DF(_QWERTY)
#define COLEMAKDH DF(_COLEMAKDH)
#define NAV MO(_NAV)
#define MEDIA MO(_MEDIA)
#define GAMING DF(_GAMING)
#define SYM MO(_SYM)
#define FUNC MO(_FUNC)
#define ADJUST MO(_ADJUST)

// ---
// QWERTY
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// COLEMAK DH
// Left-hand home row mods
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
// Not using CTL_T because redefined error
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// ---
// Shorcuts
#define GUI_ESC GUI_T(KC_ESC)
#define CTL_ESC CTL_T(KC_ESC)
#define SH_BKSP SFT_T(KC_BSPC)
#define SP_RAIS LT(_UPPER, KC_SPC)

#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)

#define KC_RESET QK_BOOT
#define KC_RST KC_RESET

#ifdef SWAP_HANDS_ENABLE
#    define KC_C1R3 SH_TT
#else // SWAP_HANDS_ENABLE
#    define KC_C1R3 KC_BSPC
#endif // SWAP_HANDS_ENABLE

#define BK_LWER LT(_LOWER, KC_BSPC)
#define SP_LWER LT(_LOWER, KC_SPC)
#define DL_RAIS LT(_UPPER, KC_DEL)
#define ET_RAIS LT(_UPPER, KC_ENTER)
#define SFT_ENT SFT_T(KC_ENTER)
#define SP_RAIS LT(_UPPER, KC_SPC)

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)

#define VIM_B LCTL(KC_LEFT)
#define VIM_W LCTL(KC_RIGHT)
