

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled_setup.c

	ifdef OCEAN_DREAM_ENABLE
		ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
			SRC += ocean_dream.c
			OPT_DEFS += -DOCEAN_DREAM_ENABLE
    	endif
	endif
	ifndef OCEAN_DREAM_ENABLE
		SRC += ocean_dream.c
		OPT_DEFS += -DOCEAN_DREAM_ENABLE
	endif

	ifdef LUNA_ENABLE
		ifeq ($(strip $(LUNA_ENABLE)), yes)
			SRC += luna.c
			OPT_DEFS += -DLUNA_ENABLE
		endif
	endif
	ifndef LUNA_ENABLE
		SRC += luna.c
		OPT_DEFS += -DLUNA_ENABLE
	endif
endif

ifdef XCASE_ENABLE
	ifeq ($(strip $(XCASE_ENABLE)), yes)
	SRC += xcase.c
	OPT_DEFS += -DXCASE_ENABLE
	endif
endif

ifdef QMK_VIM_ENABLE
	ifeq ($(strip $(QMK_VIM_ENABLE)), yes)
	include $(USER_PATH)/qmk-vim/rules.mk
	OPT_DEFS += -DQMK_VIM_ENABLE
	endif
endif

ifdef ANDREW_LEADER_ENABLE
	ifeq ($(strip $(ANDREW_LEADER_ENABLE)), yes)
	SRC += andrewleader.c
	OPT_DEFS += -DANDREW_LEADER_ENABLE
	endif
endif