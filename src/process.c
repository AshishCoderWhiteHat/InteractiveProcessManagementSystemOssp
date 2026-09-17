#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../include/process.h"

void execute_process(char **args)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        printf("Child process started. PID = %d\n", getpid());

        execvp(args[0], args);

        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Parent process. Child PID = %d\n", pid);

        waitpid(pid, NULL, 0);

        printf("Child process finished.\n");
    }
}

void execute_background_process(char **args)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        execvp(args[0], args);

        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Background process started. PID = %d\n", pid);
    }
}
