#include "render.h"

static void render_home(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 50, 20, 20, 255);
    SDL_RenderClear(renderer);
}

static void render_music(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 20, 50, 20, 255);
    SDL_RenderClear(renderer);
}

static void render_roms(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 50, 255);
    SDL_RenderClear(renderer);
}

static void render_cmds(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 50, 20, 50, 255);
    SDL_RenderClear(renderer);
}

void render_frame(SDL_Renderer *renderer, AppState *state)
{
    switch (state->current_menu)
    {
    case MENU_HOME:
        render_home(renderer);
        break;
    case MENU_MUSIC:
        render_music(renderer);
        break;
    case MENU_ROMS:
        render_roms(renderer);
        break;
    case MENU_CMDS:
        render_cmds(renderer);
        break;
    default:
        break;
    }
    SDL_RenderPresent(renderer);
}
