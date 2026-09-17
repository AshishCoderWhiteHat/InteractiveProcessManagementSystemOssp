#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "../include/signals.h"

void pause_process(char *pid)
{
    pid_t process_id = atoi(pid);

    if (kill(process_id, SIGSTOP) == -1)
    {
        perror("SIGSTOP");
        return;
    }

    printf("Process %d paused.\n", process_id);
}

void resume_process(char *pid)
{
    pid_t process_id = atoi(pid);

    if (kill(process_id, SIGCONT) == -1)
    {
        perror("SIGCONT");
        return;
    }

    printf("Process %d resumed.\n", process_id);
}

void terminate_process(char *pid)
{
    pid_t process_id = atoi(pid);

    if (kill(process_id, SIGTERM) == -1)
    {
        perror("SIGTERM");
        return;
    }

    printf("Termination signal sent to process %d.\n", process_id);
}

void kill_process(char *pid)
{
    pid_t process_id = atoi(pid);

    if (kill(process_id, SIGKILL) == -1)
    {
        perror("SIGKILL");
        return;
    }

    printf("Process %d killed.\n", process_id);
}
