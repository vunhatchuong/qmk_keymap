@ECHO OFF
SET SCRIPT_DIR=%~dp0
FOR %%A IN ("%~dp0.") DO SET QMK_FIRMWARE_DIR=%%~dpAqmk_firmware

ECHO ----------
ECHO Making Symlink for userspace:
MKLINK /D %QMK_FIRMWARE_DIR%\users\ronny %SCRIPT_DIR%users

ECHO:
ECHO ----------
ECHO Making Symlink for Sofle:
MKLINK /D %QMK_FIRMWARE_DIR%\keyboards\sofle\keymaps\ronny %SCRIPT_DIR%sofle

ECHO:
ECHO ----------
ECHO Making Symlink for Ferris Sweep:
MKLINK /D %QMK_FIRMWARE_DIR%\keyboards\ferris\keymaps\ronny %SCRIPT_DIR%sweep

ECHO:
ECHO -------------------------------- FINISHED --------------------------------

PAUSE
