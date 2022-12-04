#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include "shell.h"
#include "shellutil.h"
#include "redirect.h"

#define LINE_BUFFER_SIZE 256

//extern char *userdir;
//extern char *username;

static char currentDir[LINE_BUFFER_SIZE];

static void sigmain(int signo){
	if (signo == SIGINT){
		printf("\n\033[1m%s\033[0m %s -> ", username, currentDir);
		fflush(stdout);
	}
}
static void sigchd(int signo){ //If a program is running, it will not print the header.
	if (signo==SIGINT){
		printf("\n");
		fflush(stdout);

	}
}
	
char *getWorkDir(){
	getcwd(currentDir, LINE_BUFFER_SIZE);
	if (!strncmp(currentDir, userdir, strlen(userdir))){
		char temp[LINE_BUFFER_SIZE];
		temp[0] = '~';
		int i = strlen(userdir);
		for (;i < strlen(currentDir); i++){
			temp[i-strlen(userdir)+1] = currentDir[i];
		}
		temp[i-strlen(userdir)+1] = 0;
		strcpy(currentDir, temp);
	}

}


int main() {
	signal(SIGINT,sigmain);
	initVals();
	getWorkDir();
	printf("\033[1m%s\033[0m %s -> ", username, currentDir);
	char *line = malloc(LINE_BUFFER_SIZE);
	while (fgets(line, LINE_BUFFER_SIZE, stdin)) {
        signal(SIGINT,sigchd);	
	if (strstr(line, " ; ") || strstr(line, "; ") || strstr(line, " ;")) {
        	//printf("Semicolon detected\n");
        	line[strlen(line) - 1] = '\0';
        	semiColon(line);
        }
        else {
        	line[strlen(line) - 1] = '\0';
		stripcommand(line);
		shellexec(line);
        }
	signal(SIGINT,sigmain);
	printf("\033[1m%s\033[0m %s -> ", username, currentDir);
	}  
}   
