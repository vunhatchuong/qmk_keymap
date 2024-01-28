SRC += $(USER_PATH)/process_record.c

ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += $(USER_PATH)/encoder.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += $(USER_PATH)/oled/oled_setup.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes) # +544
    SRC += $(USER_PATH)/tap_dance.c
endif

# Combos dictionary management, remember to add #include "g/keymap_combo.h" in keymap.c
ifeq ($(strip $(COMBO_ENABLE)), yes)    ## +1888
    # VPATH +=  keyboards/gboards/
	INTROSPECTION_KEYMAP_C += combos.c
endif
