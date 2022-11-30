#include "shellutil.h"

#include <string.h>

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