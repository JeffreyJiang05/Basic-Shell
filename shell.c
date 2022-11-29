#include "shell.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <stdio.h>

#define MAX_ARGS 10

char** parse_args(char *line)
{
    int i = 0;
    char **args = (char**) malloc(sizeof(void* ) * MAX_ARGS + 1);

    char *ptr;
    while (i < MAX_ARGS && (ptr = strsep(&line, " ")))
    {
        args[i] = ptr;
        ++i;
    }

    args[i] = NULL;
    return args;
}

char shellexec(char *command)
{
    pid_t parent_pid = getpid();

    pid_t child = fork();
    if (child)
    {
        // parent
        printf("Parent Process\n");
    }
    else
    {
        // child
        printf("Child Process\n");
    } 
    return 1;
}