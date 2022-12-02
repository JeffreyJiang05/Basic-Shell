#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "shell.h"
#include "shellutil.h"
#include "redirect.h"

#define LINE_BUFFER_SIZE 256
static char currentDir[LINE_BUFFER_SIZE];
static void sigmain(int signo){
	if (signo == SIGINT){
		printf("\n\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,LINE_BUFFER_SIZE));
		fflush(stdout);
	}
}
static void sigchd(int signo){
	if (signo==SIGINT){
		printf("\n");
		fflush(stdout);

	}
}
int main() {
	signal(SIGINT,sigmain);
	printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,LINE_BUFFER_SIZE));
	char *line = malloc(LINE_BUFFER_SIZE);
	while (fgets(line, LINE_BUFFER_SIZE, stdin)) {
        if (strstr(line, " ; ") || strstr(line, "; ") || strstr(line, " ;")) {
            //printf("Semicolon detected\n");
            line[strlen(line) - 1] = '\0';
            semiColon(line);
            printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,LINE_BUFFER_SIZE));
        }
        else {
        	line[strlen(line) - 1] = '\0';
		stripcommand(line);
        	signal(SIGINT,sigchd);
		shellexec(line);
		signal(SIGINT,sigmain);
		printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,LINE_BUFFER_SIZE));
        }
    }  
}   
