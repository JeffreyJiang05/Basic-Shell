#include "shell.h"
#include <stdio.h>

int main()
{
    //char commandArr[256];
    printf("-> ");
    char *line = malloc(256);
    while (fgets(line, 256, stdin)) {
        shellexec(line);
        printf("-> ");
    }
    
    //shellexec("echo hello world");
    // shellexec("ls -l");
    // shellexec("pwd");
}