#include "redirect.h"

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "shell.h"
#include "shellutil.h"

void process_cmd_cond(struct cmd_cond *cond, char *command)
{
    cond->flag = 0;

    int tok_len = 1;
    size_t command_len = strlen(command);
    for (int i = 0; command[i]; ++i, tok_len += command[i] == ' ') {} // counts number of tokens
    char **tok_arr = malloc(tok_len * sizeof(char *));
    for (int i = 0; i < tok_len; ++i)
    {
        tok_arr[i] = strsep(&command, " "); // sep to tokens
    }

    for (int i = 0; i < tok_len; ++i)
    {
        if (strcmp(tok_arr[i], "<") == 0 && i + 1 < tok_len)
        {
            cond->flag |= cmd_in;
            strcpy(cond->in, tok_arr[i + 1]);
            ++i;
        }
        else if (strcmp(tok_arr[i], ">") == 0 && i + 1 < tok_len)
        {
            cond->flag |= cmd_out;
            cond->flag &= ~cmd_append; // turn append off
            strcpy(cond->out, tok_arr[i + 1]);
            ++i;
        }
        else if (strcmp(tok_arr[i], ">>") == 0 && i + 1 < tok_len)
        {
            cond->flag |= cmd_out | cmd_append;
            strcpy(cond->out, tok_arr[i + 1]);
            ++i;
        }
        else
        {
            cond->flag |= cmd_has_command;
            strcat(cond->core_command, tok_arr[i]);
            strcat(cond->core_command, " "); // add space back
        }
    }

    for (int i = 0; i < command_len; ++i) // restore to original
    {
        if (tok_arr[0][i] == '\0') // note tok_arr[0] should be the the beginning of the original string
        {
            tok_arr[0][i] = ' '; // replace back to space
        }
    }

    free(tok_arr);
}

void print_cmd_cond(struct cmd_cond *cond)
{
    printf("core_command: %s\n", cond->flag & cmd_has_command ? cond->core_command : "NULL");
    printf("in: %s\n", cond->flag & cmd_in ? cond->in : "STDIN");
    printf("out: %s\n", cond->flag & cmd_out ? cond->out : "STDOUT");
    printf("append: %s\n", cond->flag & cmd_append ? "True" : "False");
}

void exec_cmd(struct cmd_cond *cond)
{
    if (cond->flag & cmd_has_command)
    {
        int backup_stdin = dup(STDIN_FILENO);
        int backup_stdout = dup(STDOUT_FILENO);
        if (cond->flag & cmd_in)
        {
            int infd = open(cond->in, O_RDONLY);
            if (infd == -1) {
                printf("Input file does not exist\n");
                close(backup_stdin);
                close(backup_stdout);
                return; 
            }
            dup2(infd, STDIN_FILENO);
        }
        if (cond->flag & cmd_out)
        {

            int outfd;
            if (cond->flag & cmd_append) outfd = open(cond->out, O_CREAT | O_WRONLY | O_APPEND, 0644);
            else outfd = open(cond->out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
            if (outfd == -1)
            {
                printf("ERROR - %s\n", strerror(errno));
                close(backup_stdin);
                close(backup_stdout);
                return;
            }
            dup2(outfd, STDOUT_FILENO);
        }

        char **args = parse_args(stripcommand(cond->core_command));
        execvp(args[0], args);

        if (errno == ENOENT)
        {
            printf("No such command.\n");
            exit(0);
	    }
        else
        {
            printf("ERROR - %s\n", strerror(errno));
	        exit(0);
        }

        // cleanup
        dup2(backup_stdin, STDIN_FILENO);
        dup2(backup_stdout, STDOUT_FILENO);
    }
    else
    {
        printf("NO COMMAND SPECIFIED\n");
    }
}