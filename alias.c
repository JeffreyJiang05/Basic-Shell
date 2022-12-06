#include "alias.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

static struct alias parseAlias(char *str){
	// format: aliasname="aaa -a" or aliasname=aaa

}

int removeAlias(char *nname){
	struct alias newAlias = parseAlias(nname);
	int aliasFile = open(".aliases", O_RDONLY | O_CREAT, 0777);
	int tempFile = open(".shelltmp", O_WRONLY | O_CREAT, 0777);
	if (aliasFile == -1)
	{
		printf("ERROR - %s\n", strerror(errno));
		return -1;
	}
	struct alias temp;
	struct stat data;
	stat(".aliases", &data);
	int aliasCount = (data.st_size / sizeof(struct alias));
	for(int i = 1; i <=aliasCount; i++)
	{
		read(aliasFile, &temp, sizeof(struct alias));
		if(strcmp(newAlias.name, temp.name))
		{
			write(tempFile,&temp,sizeof(struct alias));
		}
	}
	close(aliasFile);
	close(tempFile);
	remove(".aliases");
	rename(".shelltmp", ".aliases");
	return 0;
}

void printAliasi()
{
	int savefile = open(".aliases", O_RDONLY | O_CREAT, 0777);
	if (savefile == -1)
	{
		printf("ERROR - %s\n", strerror(errno));
	} 
	else {
		struct alias temp;
		struct stat data;
		stat(".aliases",&data);
		int aliasCount = (data.st_size / sizeof(struct alias));
		for(int i = 1; i<=aliasCount; i++)
		{
			read(savefile, &temp, sizeof(struct alias));
			printf("alias %s=\'%s\'", temp.name, temp.cmd);
		}
		close(savefile);
	}
}

int addAlias(char *alname)
{
	// need work on this
	removeAlias(alname);
	int savefile = open(".aliases", O_WRONLY | O_APPEND);
	if (savefile == -1){
		printf("ERROR - %s\n", strerror(errno));
	}
	return 0;
}

