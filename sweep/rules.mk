# QMK Features
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
VIA_ENABLE = no             # +2140
TAP_DANCE_ENABLE = yes      # +544
CAPS_WORD_ENABLE = yes       # Hit both keys to enable cap for one word | +482
# COMBO_ENABLE = yes          # + 1888
SWAP_HANDS_ENABLE = yes      # one-hand typing (+490)


# External Features
CASEMODES_ENABLE = yes           # +420


#Optimize firmware size
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no           # Enabled For VIA (+796)
CONSOLE_ENABLE = yes         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
# AUTO_SHIFT_ENABLE = yes   # +2596
# LEADER_ENABLE = yes       # +1050
