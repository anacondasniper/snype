#include "render.h"
#include <SDL2/SDL_ttf.h>

static MenuItem home_items[] = {
    {"Games", MENU_ROMS},
    {"Music", MENU_MUSIC},
    {"Commands", MENU_CMDS},
    {"Settings", MENU_HOME /*placeholder*/},
};

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

/* Helpers */
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

SnypeMenu home_get_target(int cursor)
{
    return home_items[cursor].target;
}

/* Render */
static void render_home(SDL_Renderer *renderer, AppState *state)
{
    const int start_y = 50;
    const int item_height = 40;
    SDL_Color white = {255, 255, 255, 255};
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < ARRAY_LEN(home_items); i++)
    {
        int y = start_y + i * item_height;

        if (i == state->screen.home.cursor)
        {
            SDL_Rect highlight = {0, y, 480, item_height};
            SDL_SetRenderDrawColor(renderer, 100, 50, 200, 255);
            SDL_RenderFillRect(renderer, &highlight);
        }
        draw_text(renderer, state->font, home_items[i].label, 40, y + 12, white);
    }
}

static void render_music(SDL_Renderer *renderer, AppState *state)
{
    SDL_SetRenderDrawColor(renderer, 20, 50, 20, 255);
    SDL_RenderClear(renderer);
}

static void render_roms(SDL_Renderer *renderer, AppState *state)
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 50, 255);
    SDL_RenderClear(renderer);
}

static void render_cmds(SDL_Renderer *renderer, AppState *state)
{
    SDL_SetRenderDrawColor(renderer, 50, 20, 50, 255);
    SDL_RenderClear(renderer);
}

void render_frame(SDL_Renderer *renderer, AppState *state)
{
    switch (state->current_menu)
    {
    case MENU_HOME:
        render_home(renderer, state);
        break;
    case MENU_MUSIC:
        render_music(renderer, state);
        break;
    case MENU_ROMS:
        render_roms(renderer, state);
        break;
    case MENU_CMDS:
        render_cmds(renderer, state);
        break;
    default:
        break;
    }
    SDL_RenderPresent(renderer);
}
