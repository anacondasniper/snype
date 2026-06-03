#include "input.h"
#include "render.h"
#include "roms.h"
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
                        if (state->screen.roms.depth == 1)
                        {
                            state->screen.roms.depth = 0;
                            state->screen.roms.cursor = state->screen.roms.system_index;
                        }
                        else
                        {
                            state->current_menu = MENU_HOME;
                        }
                        break;
                    case SDLK_UP:
                        if (state->screen.roms.cursor > 0)
                            state->screen.roms.cursor--;
                        break;
                    case SDLK_DOWN:
                        if (state->screen.roms.depth == 1)
                        {
                            if (state->screen.roms.cursor < roms_rom_count() - 1)
                                state->screen.roms.cursor++;
                        }
                        else
                        {
                            if (state->screen.roms.cursor < roms_system_count() - 1)
                                state->screen.roms.cursor++;
                        }
                        break;
                    case SDLK_RETURN:
                        roms_scan_system(state->screen.roms.cursor);
                        state->screen.roms.depth = 1;
                        state->screen.roms.system_index = state->screen.roms.cursor;
                        state->screen.roms.cursor = 0;
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
