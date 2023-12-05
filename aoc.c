#include <stdio.h>
#include <stdlib.h>

int loadfile(char *filename, char **p){

	/** read input to memory **/

	FILE *f;
	long size;
	char *d;

	/* open file */
	f = fopen(filename, "rb");
	if(f == NULL){
		return -1;
	}

	/* getting size */
	if(fseek(f, 0, SEEK_END) != 0){
		fclose(f);
		return -1;
	}
	size = ftell(f);

	if(size <= 0 || fseek(f, 0, SEEK_SET) != 0){
		fclose(f);
		return -1;
	}

	/* copy data */
	d = (char*)malloc(size);
	if(d == NULL){
		fclose(f);
		return -1;
	}
	if( fread(d, sizeof(char), size, f) != size ){
		fclose(f);
		free(d);
		return -1;
	}
	fclose(f);

	*p = d;
	return size;
}
