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
        case SDLK_1:
            state->current_menu = MENU_HOME;
            break;
        case SDLK_2:
            state->current_menu = MENU_MUSIC;
            break;
        case SDLK_3:
            state->current_menu = MENU_ROMS;
            break;
        case SDLK_4:
            state->current_menu = MENU_CMDS;
            break;
        default:
            break;
        }
    }
}
