/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * Assignment 3
 */
#include "cs392_log.h"

void logH(char *in){				
	FILE *file;
	file = fopen("cs392_shell.log", "a");	//sets up a pointer to log file
	if(file == NULL){
		perror("Error: Failed to open file.\n");
	} else {
		fprintf(file, "%s\n", in);  	//prints commands entered to log file
	}
	fclose(file);
}

