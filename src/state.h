#pragma once

#include <SDL2/SDL_ttf.h>

typedef enum
{
    MENU_HOME,
    MENU_MUSIC,
    MENU_ROMS,
    MENU_CMDS,
} SnypeMenu;

typedef struct
{
    int running;
    SnypeMenu current_menu;
    TTF_Font *font;
} AppState;

void state_init(AppState *state);
