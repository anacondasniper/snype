#pragma once

#define MAX_SYSTEMS 32
#define MAX_ROMS 256
#define NAME_LEN 64
#define PATH_LEN 512

typedef struct
{
    char name[NAME_LEN];
    char path[PATH_LEN];
    int rom_count;
} SystemEntry;

typedef struct
{
    char name[NAME_LEN];
    char path[PATH_LEN];
} RomEntry;

void roms_scan(const char *roms_path);
int roms_system_count(void);
SystemEntry *roms_get_system(int i);

void roms_scan_system(int system_index);
int roms_rom_count(void);
RomEntry *roms_get_rom(int i);
