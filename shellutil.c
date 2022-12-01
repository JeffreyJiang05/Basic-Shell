#include "shellutil.h"
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <stdio.h>
char *stripcommand(char *cmd)
{
    int j = 0;
    for (int i = 0; cmd[i]; ++i)
    {
        if (cmd[i] != ' ' || (i > 0 && cmd[i-1] != ' '))
        {
            cmd[j++] = cmd[i];
        }
    }
    cmd[j] = '\0';
    if (cmd[strlen(cmd) - 1] == ' ')
    {
        cmd[strlen(cmd) - 1] = '\0';
    }
    return cmd;
}

void *semiColon(char * cmd) {
    char *token = strsep(&cmd, ";");
    while (token != NULL) {
        int i = 0;
        if (token[i] == ' ') {
            token = token + 1;
        }
        if ((strlen(token)) == ' ') {
            token[strlen(token)] = '\0';
        }
        token[strlen(token)] = '\0';
        stripcommand(token);
        //printf("%s\n", token);
        shellexec(token);
        token = strsep(&cmd, ";");
    }
}