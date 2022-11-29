#ifndef SHELL_CMD_H
#define SHELL_CMD_H

/**
 * exits the shell program
 */
void shellexit();

/**
 * changes the directory of the process
 * @arg path - path to change the directory into
 */
void shellcd(char *path);

#endif