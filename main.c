#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"
#include "shellutil.h"

#define LINE_BUFFER_SIZE 256

int main() {
	char currentDir[100];
	printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,100));
	char *line = malloc(LINE_BUFFER_SIZE);
	while (fgets(line, LINE_BUFFER_SIZE, stdin)) {\
        if (substring(line, " ; ") == 1 || substring(line, "; ") == 1) {
            //printf("Semicolon detected\n");
            semiColon(line);
            printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,100));
        }
        else {
            line[strlen(line) - 1] = '\0';
        	stripcommand(line);
		    shellexec(line);
		    printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,100));
        }
        	
    }
}
