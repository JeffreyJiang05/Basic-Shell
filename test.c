//Simple looping file to test running process in shell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	int i = 0;
	while (i>=0){
		printf("%d!!\n", i);
		i++;
		sleep(1);
	}	

}
