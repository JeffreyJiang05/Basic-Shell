#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#include <stdio.h>
#include "shellutil.h"

#define MAX_ARGS 10

extern char *getWorkDir();
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

    char **args = parse_args(command);
    if (strcmp(args[0], "cd") == 0) {

        if (chdir(args[1])){
		printf("Invalid directory: %s\n", args[1]);
		return 1;
	}
	getWorkDir();
        return 0;
    }
    if (strcmp(args[0], "exit") == 0){
	printf("Bye!\n");
	exit(0);
    }



    pid_t child_pid = fork();
    if (child_pid == -1)
    {
        printf("ERROR - %s\n", strerror(errno));
        return 0;
    }
    else if (child_pid)
    {
        int status;
        pid_t wait_res = waitpid(child_pid, &status, 0);
        if (wait_res == -1)
        {
            printf("ERROR - %s\n", strerror(errno));
        }
    }
    else
    {
	    //Is this when command is empty or not entered?
        execvp(args[0], args);
        
        if (errno == ENOENT)
        {
	    if (strcmp("", args[0])){
            	printf("No such command.\n");
	    }
            exit(0);
	}
        else
        {
            printf("ERROR - %s\n", strerror(errno));
	    exit(0);
        }
        
        return 0;
    }
    free(args);

    return 1;
}
