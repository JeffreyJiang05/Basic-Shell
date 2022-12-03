#ifndef REDIRECT_H
#define REDIRECT_H

struct cmd_cond
{
    char flag; // 0 0 0 0 - [has_command][append_out?][default_out?][default_in?]
    char in[255];
    char out[255];
    char core_command[255];
};

static const char cmd_in = 1 << 0;
static const char cmd_out = 1 << 1;
static const char cmd_append = 1 << 2;
static const char cmd_has_command = 1 << 3;

void process_cmd_cond(struct cmd_cond *cond, char *command);

void exec_cmd(struct cmd_cond *cond);

void print_cmd_cond(struct cmd_cond *cond);

/**
 * executes the provided command and redirects STDOUT to
 * a provided file, overwriting all previous content. 
 * corresponds the < redirection operator
 * 
 * @arg exec_command - the command to execute
 * @arg file - the destination file of STDOUT
 */
void redir_to(char *exec_command, char *file);

/**
 * executes the provided command and redirects STDOUT to
 * a provided file, appending to previous content. 
 * corresponds to the << redirection operator
 * 
 * @arg exec_command - the command to execute
 * @arg file - the destination file of STDOUT 
 */
void redir_to_append(char *exec_command, char *file);

/**
 * executes the provided command and redirect's its
 * STDIN from a provided file. 
 * corresponds to the > redirection operator
 * 
 * @arg exec_command - the command to execute
 * @arg file - the file to be STDIN 
 */
void redir_from(char *exec_command, char *file);

#endif