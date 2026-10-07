#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../include/signals.h"

void handle_sigint(int sig)
{
    printf("\nUse 'exit' to quit the Process Manager.\n");
    printf("process-manager> ");
    fflush(stdout);
}

void handle_sigchld(int sig)
{
    int status;
    pid_t pid;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        printf("\nBackground process %d finished.\n", pid);
        printf("process-manager> ");
        fflush(stdout);
    }
}

void initialize_signals(void)
{
    signal(SIGINT, handle_sigint);

    signal(SIGCHLD, handle_sigchld);
}


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
