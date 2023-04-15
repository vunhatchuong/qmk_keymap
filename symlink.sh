#!/usr/bin/env bash

printf "----------"
printf "Making Symlink for userspace:"
ln -s $HOME/qmk_firmware/users/ronny $HOME/qmk_keymap/users

printf "----------"
printf "Making Symlink for Sofle:"
ln -s $HOME/qmk_firmware/keyboards/sofle/keymaps/ronny $HOME/qmk_keymap/sofle

printf "----------"
printf "Making Symlink for Ferris Sweep:"
ln -s $HOME/qmk_firmware/keyboards/ferris/keymaps/ronny $HOME/qmk_keymap/sweep
