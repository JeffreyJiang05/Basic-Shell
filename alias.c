#include "alias.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/* Check if an alias already exists in the '.aliases' file
 * with the same name as the argument provided
 *
 * @arg name - the name of the alias to be compared
 * @return 0 if alias with the same name do not exist
 * non-zero if other aliases exist
 */
static int checkExistingAlias(char *name){
	return 0;
}

void printAliasi()
{

}

int addAlias(char *cmd)
{
	return 0;
}

int removeAlias(char *name)
{
	return 0;
}
