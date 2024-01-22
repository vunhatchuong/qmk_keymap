#pragma once

#define OLED_DISABLE_TIMEOUT
#define SPLIT_OLED_ENABLE
#define SPLIT_WPM_ENABLE

// #define COMBO_SYMBOL_ENABLE //  +682

#ifdef ARTSEY_ENABLE
#    define LAYER_STATE_16BIT
#else
#    define LAYER_STATE_8BIT
#endif

// ----- Extra features not from QMK ------
