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
#include "keycode_aliases.h"

#ifdef XCASE_ENABLE
#    include "xcase.h"
#endif

#ifdef QMK_VIM_ENABLE
#    include "./qmk-vim/src/vim.h"
#endif

#ifdef ANDREW_LEADER_ENABLE
#    include "andrewleader.h"
#endif

#ifdef OLED_ENABLE
#    include "oled_setup.h"
#endif

enum layers_name {
    _QWERTY,
    _COLEMAK_DH,
    _MOUSE,
    _MEDIA,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING,
};
