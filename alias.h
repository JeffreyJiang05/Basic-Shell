#ifndef ALIAS_H
#define ALIAS_H

struct alias
{
	char name[100];
	char cmd[255];
};

int removeAlias(char *name);

void printAliasi();

int addAlias(char *cmd);

#endif

