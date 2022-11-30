#ifndef SHELL_UTIL_H
#define SHELL_UTIL_H

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
 * remove extra spaces from the provided cmd
 * 
 * @arg cmd - the string containing the command
 * @returns the string without the extra spaces
 */
char *stripcommand(char *cmd);

#endif