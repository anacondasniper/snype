#pragma once

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
} AppState;

void state_init(AppState *state);
