#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //char commandArr[256];
    printf("-> ");
    char *line = malloc(256);
    while (fgets(line, 256, stdin)) {
        line[strlen(line) - 1] = '\0';
        shellexec(line);
        printf("-> ");
    }
    
    //shellexec("echo hello world");
    // shellexec("ls -l");
    // shellexec("pwd");
}