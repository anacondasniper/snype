#include "input.h"

void input_handle(SDL_Event *event, AppState *state)
{
    if (event->type == SDL_QUIT)
    {
        state->running = 0;
    }

    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            state->running = 0;
            break;
        default:
            break;
        }
    }
}
