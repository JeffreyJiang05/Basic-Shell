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

#endif