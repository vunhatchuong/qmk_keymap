#!/usr/bin/env bash

printf "----------"
printf "Making Symlink for userspace:"
ln -s $HOME/qmk_keymap/users $HOME/qmk_firmware/users/ronny

printf "----------"
printf "Making Symlink for Sofle:"
ln -s $HOME/qmk_keymap/sofle $HOME/qmk_firmware/keyboards/sofle/keymaps/ronny

printf "----------"
printf "Making Symlink for Ferris Sweep:"
ln -s $HOME/qmk_keymap/sweep $HOME/qmk_firmware/keyboards/ferris/keymaps/ronny
