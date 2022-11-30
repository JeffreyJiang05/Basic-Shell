#ifndef SHELL_UTIL_H
#define SHELL_UTIL_H

/**
 * remove extra spaces from the provided cmd
 * 
 * @arg cmd - the string containing the command
 * @returns the string without the extra spaces
 */
char *stripcommand(char *cmd);



/**
 * check if the provided string contains the provided substring
 * 
 * @arg line - the string to check
 * @arg sub - the substring to check for
 * @returns 1 if the string contains the substring, 0 otherwise
 */
int substring(char * line, char * sub);

/**
 * break line into individual commands and exec each command
 * @arg cmd - the string containing the command
*/
void *semiColon(char * cmd);
#endif