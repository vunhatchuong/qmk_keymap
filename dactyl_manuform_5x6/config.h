#pragma once

// #define ARTSEY_ENABLE // +520
// #define STENO_LITE_ENABLE
// #define COMBO_SYMBOL_ENABLE

#ifdef ARTSEY_ENABLE
#    define LAYER_STATE_16BIT
#else
#    define LAYER_STATE_8BIT
#endif

// ----- Extra features not from QMK ------
