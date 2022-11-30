#ifndef REDIRECT_H
#define REDIRECT_H

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