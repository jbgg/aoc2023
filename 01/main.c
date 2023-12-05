#include <stdio.h>
#include <stdlib.h>
#include "aoc.h"

int main(int argc, char *argv[]){

	if(argc < 2){
		return 0;
	}

	int size;
	char *d;

	size = loadfile(argv[1], &d);
	if(size <= 0){
		return 0;
	}
	
	int i;

	for(i=0;i<size;i++){
		printf("%c", d[i]);
	}

	/* bye */
	free(d);
	return 0;
}
