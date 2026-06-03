#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "roms.h"

static SystemEntry systems[MAX_SYSTEMS];
static RomEntry roms[MAX_ROMS];
static int system_count = 0;
static int roms_count = 0;

void roms_scan(const char *roms_path)
{
    DIR *dir = opendir(roms_path);
    if (!dir)
    {
        printf("Could not open dir: %s\n", roms_path);
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;
        if (entry->d_type == DT_DIR)
        {
            if (system_count >= MAX_SYSTEMS)
                break;
            strncpy(systems[system_count].name, entry->d_name, NAME_LEN);
            snprintf(systems[system_count].path, PATH_LEN, "%s/%s", roms_path, entry->d_name);
            systems[system_count].rom_count = 0;
            system_count++;
        }
    }
    closedir(dir);
}

int roms_system_count(void)
{
    return system_count;
}

SystemEntry *roms_get_system(int i)
{
    return &systems[i];
}

void roms_scan_system(int system_index)
{
    roms_count = 0;
    DIR *dir = opendir(systems[system_index].path);
    if (!dir)
    {
        printf("Could not open dir %s\n", systems[system_index].path);
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;
        if (entry->d_type == DT_REG)
        {
            if (roms_count >= MAX_ROMS)
                break;
            strncpy(roms[roms_count].name, entry->d_name, NAME_LEN);
            snprintf(roms[roms_count].path, PATH_LEN, "roms/%s/%s", systems[system_index].name, entry->d_name);
            roms_count++;
        }
    }
    closedir(dir);
}

int roms_rom_count(void)
{
    return roms_count;
}

RomEntry *roms_get_rom(int i)
{
    return &roms[i];
}
