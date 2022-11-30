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
    return cmd;
}

int substring(char * line, char * sub) {
    if (strstr(line, sub) != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
void *semiColon(char * cmd) {
    char *token = strsep(&cmd, ";");
    while (token != NULL) {
        printf("%s\n", token);
        shellexec(token);
        token = strsep(&cmd, ";");
    }
}