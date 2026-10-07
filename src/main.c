#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"
#include "../include/monitor.h"
#include "../include/signals.h"

int main()
{
    initialize_signals();

    char *command;
    char **tokens;

    printf("========================================\n");
    printf("   INTERACTIVE PROCESS MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    while (1)
    {
        printf("process-manager> ");

        command = read_line();

        tokens = parse_line(command);

        if (tokens[0] == NULL)
        {
            free_tokens(tokens);
            free(command);
            continue;
        }

        if (strcmp(tokens[0], "help") == 0)
        {
            printf("\nAvailable commands:\n");
            printf("help              - Show available commands\n");
            printf("run <program>     - Run a program and wait\n");
            printf("runbg <program>   - Run a program in background\n");
            printf("info <PID>        - Show process information\n");
            printf("pause <PID>       - Pause a process\n");
            printf("resume <PID>      - Resume a process\n");
            printf("terminate <PID>   - Terminate a process\n");
            printf("kill <PID>        - Force kill a process\n");
            printf("exit              - Exit the process manager\n\n");
        }
        else if (strcmp(tokens[0], "run") == 0)
        {
            if (tokens[1] == NULL)
            {
                printf("Usage: run <program> [arguments]\n");
            }
            else
            {
                execute_process(&tokens[1]);
            }
        }
        else if (strcmp(tokens[0], "runbg") == 0)
        {
            if (tokens[1] == NULL)
            {
                printf("Usage: runbg <program> [arguments]\n");
            }
            else
            {
                execute_background_process(&tokens[1]);
            }
        }
        else if (strcmp(tokens[0], "info") == 0)
        {
            if (tokens[1] == NULL)
            {
                printf("Usage: info <PID>\n");
            }
            else
            {
                show_process_info(tokens[1]);
            }
        }
        else if (strcmp(tokens[0], "pause") == 0)
        {
            if (tokens[1] == NULL)
            {
                printf("Usage: pause <PID>\n");
            }
            else
            {
                pause_process(tokens[1]);
            }
        }
        else if (strcmp(tokens[0], "resume") == 0)
        {
            if (tokens[1] == NULL)
            {
                printf("Usage: resume <PID>\n");
            }
            else
            {
                resume_process(tokens[1]);
            }
        }
        else if (strcmp(tokens[0], "terminate") == 0)
        {
            if (tokens[1] == NULL)
            {
                printf("Usage: terminate <PID>\n");
            }
            else
            {
                terminate_process(tokens[1]);
            }
        }
        else if (strcmp(tokens[0], "kill") == 0)
        {
            if (tokens[1] == NULL)
            {
                printf("Usage: kill <PID>\n");
            }
            else
            {
                kill_process(tokens[1]);
            }
        }
        else if (strcmp(tokens[0], "exit") == 0)
        {
            free_tokens(tokens);
            free(command);

            printf("Exiting Process Manager...\n");
            break;
        }
        else
        {
            printf("Unknown command: %s\n", tokens[0]);
        }

        free_tokens(tokens);
        free(command);
    }

    return 0;
}
