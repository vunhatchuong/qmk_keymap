#pragma once

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 170 // 175 or 170 seems popular default: 200
#define PERMISSIVE_HOLD
// #undef PERMISSIVE_HOLD

// #define HOLD_ON_OTHER_KEY_PRESS

#ifdef MOUSEKEY_ENABLE
#    define MK_KINETIC_SPEED
#    define MOUSEKEY_INITIAL_SPEED 20
#    define MK_VARIANT MK_TYPE_KINETIC
#endif

#ifdef COMBO_ENABLE
// #define COMBO_STRICT_TIMER
// #define EXTRA_SHORT_COMBOS
#    define COMBO_TERM 25 // or precondition: 70 default: 50
#    define COMBO_SHOULD_TRIGGER
// #    define COMBO_ONLY_FROM_LAYER 0
#endif

#ifdef CAPS_WORD_ENABLE
#    define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#endif

#ifdef LEADER_ENABLE
#    define LEADER_PER_KEY_TIMING
#    define LEADER_TIMEOUT 250
#    define LEADER_NO_TIMEOUT
#endif

#ifndef ONESHOT_TAP_TOGGLE
#    define ONESHOT_TAP_TOGGLE 2 // Default: 5
#endif

#ifndef ONESHOT_TIMEOUT
#    define ONESHOT_TIMEOUT 3000 // Default: 5000
#endif

// Disable unnecessary features to save firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// #define NO_ACTION_ONESHOT // +658

// Save firmware space
// Strip away all prints except `uprintf`
#define USER_PRINT
