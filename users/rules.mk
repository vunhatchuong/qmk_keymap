SRC += $(USER_PATH)/process_record.c

ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += $(USER_PATH)/encoder.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += $(USER_PATH)/oled/oled_setup.c

    ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)  # +2804
        SRC += $(USER_PATH)/oled/ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif

    ifeq ($(strip $(LUNA_ENABLE)), yes)         # +1458
        SRC += $(USER_PATH)/oled/luna.c
        OPT_DEFS += -DLUNA_ENABLE
    endif
endif

ifeq ($(strip $(CASEMODES_ENABLE)), yes) # +420
    SRC += $(USER_PATH)/features/casemodes.c
    OPT_DEFS += -DCASEMODES_ENABLE
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes) # +544
    SRC += $(USER_PATH)/tap_dance.c
endif

# Combos dictionary management, remember to add #include "g/keymap_combo.h" in keymap.c
ifeq ($(strip $(COMBO_ENABLE)), yes)    ## +1888
    # VPATH +=  keyboards/gboards/
    SRC += $(USER_PATH)/combo.c
endif

ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes) # +2596
    SRC += $(USER_PATH)/auto_shift.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes) # +1050
    SRC += $(USER_PATH)/leader.c
endif
