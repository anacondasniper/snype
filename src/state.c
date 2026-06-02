#include "state.h"

void state_init(AppState *state)
{
    state->running = 1;
    state->current_menu = MENU_HOME;
}
