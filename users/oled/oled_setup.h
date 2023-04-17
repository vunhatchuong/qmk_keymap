#pragma once

#include "quantum.h"
#ifdef OLED_ENABLE
#    include "oled_driver.h"
#    define OLED_RENDER_WPM_COUNTER " WPM: "
#endif
#ifdef LUNA_ENABLE
#    include "luna.h"
#endif
#ifdef OCEAN_DREAM_ENABLE
#    include "ocean_dream.h"
#endif
