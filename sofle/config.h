#pragma once

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_DISABLE_TIMEOUT
#define SPLIT_OLED_ENABLE
#define SPLIT_WPM_ENABLE

// #define ARTSEY_ENABLE   // +520
// #define STENO_LITE_ENABLE   // +578
// #define COMBO_SYMBOL_ENABLE //  +682
// #define SECRET_COMBO_ENABLE

#ifdef ARTSEY_ENABLE
#    define LAYER_STATE_16BIT
#else
#    define LAYER_STATE_8BIT
#endif

// ----- Extra features not from QMK ------
