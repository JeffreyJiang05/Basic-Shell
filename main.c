#include "shell.h"

int main()
{
    char cmd[] = "pwd";
    shellexec(cmd);
    // shellexec("ls -l");
    // shellexec("pwd");
}