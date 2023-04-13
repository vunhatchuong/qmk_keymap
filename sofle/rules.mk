ENCODER_ENABLE = yes
# OLED
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
OCEAN_DREAM_ENABLE = no    # +2804
LUNA_ENABLE = yes          # +1458


# QMK Features
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
VIA_ENABLE = no             # +2140
TAP_DANCE_ENABLE = yes      # +544
CAPS_WORD_ENABLE = yes       # Hit both keys to enable cap for one word | +482
COMBO_ENABLE = yes          # + 1888
SWAP_HANDS_ENABLE = yes      # one-hand typing (+490)


# External Features
XCASE_ENABLE = no           # +626
QMK_VIM_ENABLE = no         # +2358
ANDREW_LEADER_ENABLE = no   # +372 not include LED


#Optimize firmware size
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no           # Enabled For VIA (+796)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
