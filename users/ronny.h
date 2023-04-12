/*
Copyright 2021 Tyler Thrailkill <@snowe/@snowe2010>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"
#include "process_record.h"

#ifdef XCASE_ENABLE
#    include "feature/xcase.h"
#endif

#ifdef QMK_VIM_ENABLE
#    include "feature/qmk-vim/src/vim.h"
#endif

#ifdef ANDREW_LEADER_ENABLE
#    include "features/andrewleader.h"
#endif

#ifdef OLED_ENABLE
#    include "oled/oled_setup.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "tap_dance.h"
#endif

enum layer_names {
    _QWERTY,
    _COLEMAKDH,
    _GAMING,
    _NAV,
    _MEDIA,
    _SYM,
    _FUNC,
    _ADJUST,
};
