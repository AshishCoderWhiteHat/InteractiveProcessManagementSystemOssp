#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/monitor.h"

void show_process_info(char *pid)
{
    char path[100];
    char line[256];

    snprintf(path, sizeof(path), "/proc/%s/status", pid);

    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Process with PID %s not found.\n", pid);
        return;
    }

    printf("\n--------------------------------\n");
    printf("Process Information\n");
    printf("--------------------------------\n");

    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Pid:", 4) == 0 ||
            strncmp(line, "PPid:", 5) == 0)
        {
            printf("%s", line);
        }
    }

    printf("--------------------------------\n");

    fclose(file);
}
