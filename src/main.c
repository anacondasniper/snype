#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "input.h"
#include "state.h"
#include "render.h"

#include "roms.h"

#define WINDOW_W 480
#define WINDOW_H 320

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("SDL init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Snype",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_W, WINDOW_H,
        0);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    AppState state;
    state_init(&state);
    roms_scan("roms/");

    TTF_Init();
    state.font = TTF_OpenFont("assets/fonts/JetBrainsMonoNerdFont-Regular.ttf", 16);
    if (!state.font)
    {
        SDL_Log("Font load failed: %s", TTF_GetError());
        return 1;
    }

    SDL_Event event;

    while (state.running)
    {
        while (SDL_PollEvent(&event))
        {
            input_handle(&event, &state);
        }
        render_frame(renderer, &state);
    }
    TTF_CloseFont(state.font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
