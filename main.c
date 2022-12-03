#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"
#include "shellutil.h"
#include "redirect.h"

#define LINE_BUFFER_SIZE 256

int main() {

    char buffer[LINE_BUFFER_SIZE] = "> copy.txt ls < main.c -al < redirect.h >> text.txt";
    struct cmd_cond cond;
    process_cmd_cond(&cond, buffer); 
    print_cmd_cond(&cond);
    
	char currentDir[100];
	printf("\033[1m%s\033[0m %s -> ", getlogin(), getcwd(currentDir,100));
	char *line = malloc(LINE_BUFFER_SIZE);
	while (fgets(line, LINE_BUFFER_SIZE, stdin)) {
        if (strstr(line, " ; ") || strstr(line, "; ") || strstr(line, " ;")) {
            //printf("Semicolon detected\n");
            line[strlen(line) - 1] = '\0';
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
