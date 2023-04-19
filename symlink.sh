#!/usr/bin/env bash

# dir of script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )";
# parent dir of that dir
QMK_FIRMWARE_DIR="${SCRIPT_DIR%/*}/qmk_firmware"

printf "Making Symlink for userspace:"
ln -s $SCRIPT_DIR/users $QMK_FIRMWARE_DIR/users/ronny

printf "\nMaking Symlink for Sofle:"
ln -s $SCRIPT_DIR/sofle $QMK_FIRMWARE_DIR/keyboards/sofle/keymaps/ronny

printf "\nMaking Symlink for Ferris Sweep:"
ln -s $SCRIPT_DIR/sweep $QMK_FIRMWARE_DIR/keyboards/ferris/keymaps/ronny
