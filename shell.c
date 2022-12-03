#include "shell.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>

#include "shellutil.h"

char shellexec(char *command)
{
    pid_t parent_pid = getpid();

    stripcommand(command);
    if (strncmp(command, "cd", 2) == 0) 
    {
        char path[255];
        int has_path = sscanf(command, "cd %s", path);
        printf("%s]\n", command);
        chdir(has_path ? path : "");
        return 0;
    }
    if (strncmp(command, "exit", 4) == 0)
    {
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
        // execvp(args[0], args);
        
        if (errno == ENOENT)
        {
            printf("No such command.\n");
            exit(0);
	    }
        else
        {
            printf("ERROR - %s\n", strerror(errno));
	        exit(0);
        }
        
        return 0;
    }

    return 1;
}
