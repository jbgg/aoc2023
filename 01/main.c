#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
	int suma;

	suma = 0;

	char first;
	char last;

	i = 0;
	while(i<size){
		while(i < size && d[i] != '\n' && isdigit(d[i]) == 0){
			i++;
		}
		if(i < size && d[i] != '\n'){ /* isdigit(d[i]) != 0 */
			first = d[i];
			i++;
			last = first;
			while(i < size && d[i] != '\n'){
				if(isdigit(d[i])){
					last = d[i];
				}
				i++;
			}
			suma += (first - '0')*10 + (last - '0');
		}
		i++;
	}

	printf("%d\n", suma);

	/* bye */
	free(d);
	return 0;
}
