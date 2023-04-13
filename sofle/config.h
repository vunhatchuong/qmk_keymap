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

#pragma once

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_DISABLE_TIMEOUT
#define SPLIT_OLED_ENABLE
#define LAYER_STATE_8BIT
#define SPLIT_WPM_ENABLE

#define NO_ACTION_ONESHOT // +658

// ----- Extra features not from QMK ------

// #define LEADER_DISPLAY_STR // +232

// #define BETTER_VISUAL_MODE      // +174
// #define VIM_W_BEGINNING_OF_WORD // +108
// #define VIM_REPLACE             // +76
// #define VIM_PASTE_BEFORE        // +60
// #define VIM_G_MOTIONS           // +116
