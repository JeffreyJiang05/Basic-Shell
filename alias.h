#ifndef ALIAS_H
#define ALIAS_H

struct alias
{
	char name[100];
	char cmd[255];
};

void printAliasi();

int addAlias(char *cmd);

int removeAlias(char *name);
#endif

