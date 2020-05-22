/*
 * Assignment 1 CS 392
 * February 15, 2019
 * I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
*/

#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

ulong aLength;

int comp(const void* fst, const void* snd){
	//Issues a comarison to be used in quicksort function in main function.
	uint f = *(uint*)fst; //f and s for first item and second item respectively.
	uint s = *(uint*)snd;
	if(f < s){
		return -1;
	} else if(f > s){
		return 1;
	} else {
		return 0;
	}
}

uint* rArray(char* file){ 
	/* Reads information from input file.
	* Issues minor checks on pointers and uses file streams to accomplish reading correctly.
	* Frees pointers to prevent memory issues.
	*/
	char* str;
	uint* arr;
	size_t size;
	FILE *fpointer = fopen(file, "rb");
	if(fpointer == NULL){
		printf("File cannot be opened. Error: %d\n", errno);
		exit(1);
	}
	fseek(fpointer, 0L, SEEK_END);
	size = ftell(fpointer);
	rewind(fpointer);
	str = malloc(size + 1);
	arr = malloc(size + 1);
	if(str == NULL || arr == NULL){
		printf("Error: %d\n", errno);
		free(str);
		free(arr);
		exit(1);
	}
	for (size_t i = 0; i < size + 1; i++){
		str[i] = 0;
	}

	size_t i = 0;

	while(fgets(str, size, fpointer) != NULL){
		if(ferror(fpointer)){
			printf("Error: %d\n", errno);
		}
		arr[i] = atoi(str);
		i++;
	}
	aLength = i;
	free(str);
	fclose(fpointer);
	return arr;
}


void out(uint* n, char* file){
	/* Handles outputting to the desired output file with minor pointer checks.
	 * Writes to output file in correct binary format.
	*/
	FILE *fpointer = fopen(file, "wb");
	if(fpointer == NULL){
		printf("Error: %d\n", errno);
		exit(1);
	}
	fwrite(n, sizeof(uint), aLength, fpointer);
	fclose(fpointer);		
}

int main (int argc, char** argv){
	/* Handles minor input checking (argv[1] is the input file, argv[2] is the output file)	
	 * Uses a built in quicksort function to perform sort operation as desired.
	 * Cleans up and give desired output. 
	*/
	if(argc != 3){
		fprintf(stderr, "Invalid number of arguments.");
		exit(1);					 
	}

	aLength = 0;
	uint *contents = rArray(argv[1]);
	qsort(contents, aLength, sizeof(uint), comp);
	out(contents, argv[2]);
	free(contents);
	exit(0);
}

