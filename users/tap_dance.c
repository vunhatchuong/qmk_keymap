#include "tap_dance.h"

void td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        reset_keyboard();
    }
}

void td_change_to_qwerty(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        default_layer_set(1UL<<_QWERTY);
    }
}
void td_change_to_colemakdh(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        default_layer_set(1UL<_COLEMAKDH);
    }
}
tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_FN(td_fn_boot),
    [TD_QWERTY] = ACTION_TAP_DANCE_FN(td_change_to_qwerty),
    [TD_COLEMAKDH] = ACTION_TAP_DANCE_FN(td_change_to_colemakdh),
};