@ECHO OFF
ECHO ----------
ECHO Making Symlink for userspace:
mklink /D D:\qmk_firmware\users\ronny D:\qmk_keymap\users

ECHO ----------
ECHO Making Symlink for Sofle:
mklink /D D:\qmk_firmware\keyboards\sofle\keymaps\ronny D:\qmk_keymap\sofle

ECHO ----------
ECHO Making Symlink for Ferris Sweep:
mklink /D D:\qmk_firmware\keyboards\ferris\keymaps\ronny D:\qmk_keymap\sweep

PAUSE
