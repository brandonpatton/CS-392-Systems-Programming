/*
 * Assignment 1 CS392
 * February 11, 2019
 * I pledge my honor that I have abided by the Stevens Honor System
 * Brandon Patton
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



void cat (FILE *file, unsigned int size, char *contents){
	/* Reads from input file and writes to output the contents of the file
	* Uses file streams to do so.	
	*/
	fread(contents, 1, size, file);
	fwrite(contents, 1, size, stdout);	
}

int main (int argc, char** argv){
	/* Handles the majority of input checking
	 * Find the size of the file using fseek to get to the end of the file and then employs
	 * ftell to receive the size, then uses fseek to return to the beginning of the file.
	 * Cleans up stream uses and frees memory when finished.
	*/
	FILE *fpointer;
	if (argc != 2){
		perror("Error: ");
		exit(1);
	}
	fpointer = fopen(argv[1], "r"); 
	
	if (fpointer == NULL){
		perror("Error: ");
		exit(1);
							
	}
	if(fseek(fpointer, 0, SEEK_END) !=0 ){
		perror("Error: ");
		exit(1);
	} 
	unsigned int size = ftell(fpointer);
	if(size == -1){
		perror("Error: ");
		exit(1);
	}
	if(fseek(fpointer, 0, SEEK_SET)){
		perror("Error: ");
		exit(1);
	}
	char *memaloc;
	memaloc = (char *) malloc (size);
	cat(fpointer, size, memaloc);
	if(fclose(fpointer) !=0){ 
		perror("Error: ");
	}
	free(memaloc);
	exit(0);
}
