#include "launcher.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    const char *system;
    const char *emulator;
} EmulatorEntry;

static EmulatorEntry emulator_map[] = {
    {"gb", "mgba"},
    {"gba", "mgba"},
    {"nes", "fceux"},
    {"snes", "snes9x"},
};

const char *launcher_get_emulator(const char *system)
{
    for (int i = 0; i < sizeof(emulator_map) / sizeof(emulator_map[0]); i++)
    {
        EmulatorEntry entry = emulator_map[i];
        if (strcmp(entry.system, system) == 0)
            return entry.emulator;
    }
    return NULL;
}

void launcher_run(const char *emulator, const char *rom_path)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execlp(emulator, emulator, rom_path, NULL);
        perror("execlp failed");
        _exit(1);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        perror("fork failed");
    }
}
