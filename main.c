#include "shell.h"

int main()
{
    char cmd[] = "cd ..";
    shellexec(cmd);
    char cmd1[] = "pwd";
    shellexec(cmd1);
    // shellexec("ls -l");
    // shellexec("pwd");
}