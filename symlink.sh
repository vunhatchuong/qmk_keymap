#!/usr/bin/env bash

# dir of script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )";
# parent dir of that dir
QMK_FIRMWARE_DIR="${SCRIPT_DIR%/*}/qmk_firmware"

echo $SCRIPT_DIR
echo $QMK_FIRMWARE_DIR

printf "Making Symlink for userspace"
ln -s $SCRIPT_DIR/users $QMK_FIRMWARE_DIR/users/ronny

printf "\nMaking Symlink for Sofle"
ln -s $SCRIPT_DIR/sofle $QMK_FIRMWARE_DIR/keyboards/sofle/keymaps/ronny

printf "\nMaking Symlink for Ferris Sweep"
ln -s $SCRIPT_DIR/sweep $QMK_FIRMWARE_DIR/keyboards/ferris/keymaps/ronny

printf "\nMaking Symlink for Dactyl Manuform 5x6"
ln -s $SCRIPT_DIR/dactyl_manuform_5x6 $QMK_FIRMWARE_DIR/keyboards/handwired/dactyl_manuform/5x6/keymaps/ronny
