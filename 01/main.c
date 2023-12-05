#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	if(argc < 2){
		return 0;
	}


	/** read input to memory **/

	/* open file */
	FILE *f;
	f = fopen(argv[1], "rb");
	if(f == NULL){
		return 0;
	}

	/* getting size */
	long size;
	if(fseek(f, 0, SEEK_END) != 0){
		fclose(f);
		return 0;
	}
	size = ftell(f);
	if(fseek(f, 0, SEEK_SET) != 0){
		fclose(f);
		return 0;
	}

	/* copy data */
	char *d;
	d = (char*)malloc(size);
	if(d == NULL){
		fclose(f);
		return 0;
	}
	if( fread(d, sizeof(char), size, f) != size ){
		fclose(f);
		free(d);
		return 0;
	}
	fclose(f);

	printf("size = %ld\n", size);


	free(d);

	return 0;
}
