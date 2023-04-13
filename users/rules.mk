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

ifeq ($(strip $(XCASE_ENABLE)), yes) # +626
    SRC += $(USER_PATH)/features/xcase.c
    OPT_DEFS += -DXCASE_ENABLE
endif

ifeq ($(strip $(QMK_VIM_ENABLE)), yes) # +2358
    include $(USER_PATH)/features/qmk-vim/rules.mk
    OPT_DEFS += -DQMK_VIM_ENABLE
endif

ifeq ($(strip $(ANDREW_LEADER_ENABLE)), yes) # +372 not include LED
    SRC += $(USER_PATH)/features/andrewleader.c
    OPT_DEFS += -DANDREW_LEADER_ENABLE
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes) # +544
    SRC += $(USER_PATH)/tap_dance.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)    ## +1888
    SRC += combo.c
endif
