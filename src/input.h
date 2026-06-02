#pragma once

#include <SDL2/SDL.h>

typedef struct
{
    int running;
} AppState;

void input_handle(SDL_Event *event, AppState *state);
