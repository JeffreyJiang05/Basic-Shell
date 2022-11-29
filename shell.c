#include "shell.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

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
    if (child == -1)
    {
        printf("ERROR - %s\n", strerror(errno));
    }
    else if (child)
    {
        int status;
        pid_t wait_res = waitpid(child, &status, 0);
        if (wait_res == -1)
        {
            printf("ERROR - %s\n", strerror(errno));
        }
    }
    else
    {
        char **args = parse_args(command);
        execvp(args[0], args);
        
        printf("ERROR - %s\n", strerror(errno));
    }
    return 1;
}