#include <stdio.h>
#include <stdlib.h>
#include "../include/input.h"

#define INITIAL_SIZE 64

char *read_line(void)
{
    int size = INITIAL_SIZE;
    int position = 0;

    char *buffer = malloc(size);

    if (buffer == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int ch;

    while (1)
    {
        ch = getchar();

        if (ch == '\n' || ch == EOF)
        {
            buffer[position] = '\0';
            return buffer;
        }

        buffer[position] = ch;
        position++;

        if (position >= size - 1)
        {
            size = size * 2;

            buffer = realloc(buffer, size);

            if (buffer == NULL)
            {
                printf("Memory reallocation failed.\n");
                exit(1);
            }
        }
    }
}
