#pragma once

#include <SDL2/SDL_ttf.h>

typedef enum
{
    MENU_HOME,
    MENU_MUSIC,
    MENU_ROMS,
    MENU_CMDS,
    MENU_CFG,
} SnypeMenu;

typedef struct
{
    int cursor;
} HomeState;
typedef struct
{
    int cursor;
} MusicState;
typedef struct
{
    int cursor;
} RomsState;
typedef struct
{
    int cursor;
} CmdsState;
typedef struct
{
    int cursor;
} CfgState;
typedef union
{
    HomeState home;
    MusicState music;
    RomsState roms;
    CmdsState cmds;
    CfgState cfg;
} ScreenData;

typedef struct
{
    int running;
    SnypeMenu current_menu;
    ScreenData screen;
    TTF_Font *font;
} AppState;

void state_init(AppState *state);
