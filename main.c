#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char currentDir[100];
	printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,100));
	char *line = malloc(256);
	while (fgets(line, 256, stdin)) {
        	line[strlen(line) - 1] = '\0';
        	shellexec(line);
		printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,100));
    	}
}
