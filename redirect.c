#include "redirect.h"

#include <fcntl.h>
#include <unistd.h>

#include "shellutil.h"

void redir_to(char *exec_command, char *file)
{
    int outfd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    int backup_stdout = dup(STDOUT_FILENO);
    dup2(outfd, STDOUT_FILENO);

    shellexec(exec_command);

    dup2(backup_stdout, STDERR_FILENO);
}