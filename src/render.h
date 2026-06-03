#pragma once

#include <SDL2/SDL.h>
#include "state.h"

typedef struct
{
    const char *label;
    SnypeMenu target;
} MenuItem;

SnypeMenu home_get_target(int cursor);
void render_frame(SDL_Renderer *renderer, AppState *state);
