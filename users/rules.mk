ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled_setup.c

    ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
        SRC += ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif

    ifeq ($(strip $(LUNA_ENABLE)), yes)
        SRC += luna.c
        OPT_DEFS += -DLUNA_ENABLE
    endif
endif

ifeq ($(strip $(XCASE_ENABLE)), yes)
    SRC += $(USER_PATH)/features/xcase.c
    OPT_DEFS += -DXCASE_ENABLE
endif

ifeq ($(strip $(QMK_VIM_ENABLE)), yes)
    include $(USER_PATH)/features/qmk-vim/rules.mk
    OPT_DEFS += -DQMK_VIM_ENABLE
endif

ifeq ($(strip $(ANDREW_LEADER_ENABLE)), yes)
    SRC += $(USER_PATH)/features/andrewleader.c
    OPT_DEFS += -DANDREW_LEADER_ENABLE
endif
