#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BUFFER_SIZE 256

int main()
{
    printf("-> ");
    char *line = malloc(LINE_BUFFER_SIZE);
    while (fgets(line, LINE_BUFFER_SIZE, stdin)) 
    {
        line[strlen(line) - 1] = '\0';
        shellexec(line);
        printf("-> ");
    }
}