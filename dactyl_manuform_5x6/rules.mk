# QMK Features
MOUSEKEY_ENABLE = yes       # +4700
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
VIA_ENABLE = no             # +2140
TAP_DANCE_ENABLE = yes      # +544
CAPS_WORD_ENABLE = yes       # Hit both keys to enable cap for one word | +482
# COMBO_ENABLE = yes          # + 1888
SWAP_HANDS_ENABLE = yes      # one-hand typing (+490)
STENO_ENABLE = yes
STENO_PROTOCOL = geminipr

# External Features

#Optimize firmware size
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no           # Enabled For VIA (+796)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration

ifeq ($(strip $(SWAP_HANDS_ENABLE)), yes)
    SRC += swap_hand.c
endif

ifeq ($(strip $(STENO_ENABLE)), yes)
    NKRO_ENABLE = yes
    FORCE_NKRO = yes
endif
