#include "launcher.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

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
