#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"
#include "shellutil.h"

#define LINE_BUFFER_SIZE 256

int main()
{
    printf("-> ");
    char *line = malloc(LINE_BUFFER_SIZE);
    while (fgets(line, LINE_BUFFER_SIZE, stdin)) 
    {
        line[strlen(line) - 1] = '\0';
        stripcommand(line);
        if (substring(line, " ; ") == 1 || substring(line, "; ") == 1) {
            //printf("Semicolon detected\n");
            semiColon(line);
            printf("-> ");
        }
        else {
            shellexec(line);
            printf("-> ");
        }
        
    }
}
