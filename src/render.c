#include "render.h"
#include "roms.h"
#include <SDL2/SDL_ttf.h>

static MenuItem home_items[] = {
    {"Games", MENU_ROMS},
    {"Music", MENU_MUSIC},
    {"Commands", MENU_CMDS},
    {"Settings", MENU_CFG},
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

static void render_header(SDL_Renderer *renderer, AppState *state, const char *title)
{
    SDL_Color white = {255, 255, 255, 255};
    draw_text(renderer, state->font, title, 20, 15, white);
    draw_text(renderer, state->font, "snype v0.1.0", 350, 15, white);
}

static void render_background(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
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
    render_background(renderer, 50, 50, 50);
    render_header(renderer, state, "Hello, user");

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
}

static void render_roms(SDL_Renderer *renderer, AppState *state)
{
    const int start_y = 50;
    const int item_height = 40;
    SDL_Color white = {255, 255, 255, 255};
    render_background(renderer, 50, 50, 50);
    render_header(renderer, state, "Games");

    if (state->screen.roms.depth)
    {
        for (int i = 0; i < roms_rom_count(); i++)
        {
            int y = start_y + i * item_height;

            if (i == state->screen.roms.cursor)
            {
                SDL_Rect highlight = {0, y, 480, item_height};
                SDL_SetRenderDrawColor(renderer, 100, 50, 200, 255);
                SDL_RenderFillRect(renderer, &highlight);
            }
            draw_text(renderer, state->font, roms_get_rom(i)->name, 40, y + 12, white);
        }
    }
    else
    {
        for (int i = 0; i < roms_system_count(); i++)
        {
            int y = start_y + i * item_height;

            if (i == state->screen.roms.cursor)
            {
                SDL_Rect highlight = {0, y, 480, item_height};
                SDL_SetRenderDrawColor(renderer, 100, 50, 200, 255);
                SDL_RenderFillRect(renderer, &highlight);
            }
            draw_text(renderer, state->font, roms_get_system(i)->name, 40, y + 12, white);
        }
    }
}

static void render_cmds(SDL_Renderer *renderer, AppState *state)
{
    SDL_SetRenderDrawColor(renderer, 50, 20, 50, 255);
    SDL_RenderClear(renderer);
}

static void render_cfg(SDL_Renderer *renderer, AppState *state)
{
    SDL_SetRenderDrawColor(renderer, 20, 50, 50, 255);
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
        case MENU_CFG:
            render_cfg(renderer, state);
            break;
        default:
            break;
    }
    SDL_RenderPresent(renderer);
}
