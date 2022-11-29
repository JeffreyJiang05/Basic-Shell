#ifndef SHELL_H
#define SHELL_H

/**
 * parse a string into an array of strings with each pointer
 * pointing at each argument
 * 
 * should be deallocated execept in the case or an exec family
 * function. the os will free the memory automatically.
 * 
 * @arg line - the line containing the command to parse
 * @return dyanmically allocated array pointing to strings
*/
char** parse_args(char *line);

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