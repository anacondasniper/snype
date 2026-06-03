#include "input.h"
#include "render.h"
void input_handle(SDL_Event *event, AppState *state)
{
    if (event->type == SDL_QUIT)
    {
        state->running = 0;
    }

    if (event->type == SDL_KEYDOWN)
    {
        if (event->key.keysym.sym == SDLK_ESCAPE)
            state->running = 0;

        switch (state->current_menu)
        {
        case MENU_HOME:
            switch (event->key.keysym.sym)
            {
            case SDLK_UP:
                if (state->screen.home.cursor > 0)
                    state->screen.home.cursor--;
                break;
            case SDLK_DOWN:
                if (state->screen.home.cursor < 3)
                    state->screen.home.cursor++;
                break;
            case SDLK_RETURN:
                state->current_menu =
                    home_get_target(state->screen.home.cursor);
                break;
            default:
                break;
            }
            break;
        case MENU_MUSIC:
            switch (event->key.keysym.sym)
            {
            case SDLK_BACKSPACE:
                state->current_menu = MENU_HOME;
                break;
            default:
                break;
            }
            break;
        case MENU_ROMS:
            switch (event->key.keysym.sym)
            {
            case SDLK_BACKSPACE:
                state->current_menu = MENU_HOME;
                break;
            default:
                break;
            }
            break;
        case MENU_CMDS:
            switch (event->key.keysym.sym)
            {
            case SDLK_BACKSPACE:
                state->current_menu = MENU_HOME;
                break;
            default:
                break;
            }
            break;
        case MENU_CFG:
            switch (event->key.keysym.sym)
            {
            case SDLK_BACKSPACE:
                state->current_menu = MENU_HOME;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}
