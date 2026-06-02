#include "render.h"
#include <SDL2/SDL_ttf.h>

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

static void draw_text(SDL_Renderer *renderer, TTF_Font *font,
                      const char *text, int x, int y, SDL_Color color)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect dst = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    SDL_DestroyTexture(texture);
}

void render_frame(SDL_Renderer *renderer, AppState *state)
{
    SDL_Color white = {255, 255, 255, 255};
    switch (state->current_menu)
    {
    case MENU_HOME:
        render_home(renderer);
        draw_text(renderer, state->font, "SNYPE HOME", 20, 20, white);
        break;
    case MENU_MUSIC:
        render_music(renderer);
        draw_text(renderer, state->font, "SNYPE MUSIC", 20, 20, white);
        break;
    case MENU_ROMS:
        render_roms(renderer);
        draw_text(renderer, state->font, "SNYPE ROMS", 20, 20, white);
        break;
    case MENU_CMDS:
        render_cmds(renderer);
        draw_text(renderer, state->font, "SNYPE CMDS", 20, 20, white);
        break;
    default:
        break;
    }
    SDL_RenderPresent(renderer);
}
