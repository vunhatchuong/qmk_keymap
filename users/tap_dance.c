#include "tap_dance.h"

void td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        reset_keyboard();
    }
}

void td_change_to_qwerty(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        default_layer_set((layer_state_t)1 << _QWERTY);
    }
}

void td_change_to_colemakdh(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        default_layer_set((layer_state_t)1 << _COLEMAKDH);
    }
}

#ifdef ARTSEY_ENABLE
void td_change_to_artsey(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        default_layer_set((layer_state_t)1 << _ARTSEY);
    }
}
#endif

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [BOOT_TD] = ACTION_TAP_DANCE_FN(td_fn_boot),
    [QWERTY_TD] = ACTION_TAP_DANCE_FN(td_change_to_qwerty),
    [COLEMAKDH_TD] = ACTION_TAP_DANCE_FN(td_change_to_colemakdh),
#ifdef ARTSEY_ENABLE
    [ARTSEY_TD] = ACTION_TAP_DANCE_FN(td_change_to_artsey)
#endif
};
//clang-format on
