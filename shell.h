#ifndef SHELL_H
#define SHELL_H


/**
 * splits the current process and executes the provided command
 * in the child process. The parent process will wait until the 
 * child process has finished.
 * 
 * @arg command - the command to execute as a string
 * @return a boolean that signifies if the command was successful or failed
 */
char shellexec(char *command);

#endif
