/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * Assignment 3
 */

#include "cs392_exec.h"

int arguments;  			//declaration here for easy use throughout functions

char **getWords(char* input){
	arguments = 1;			//counts the number of arguments on the command line
	for(int i = 0; input[i] != '\0'; i++){	
		if (input[i] == ' '){
			arguments++;
		}
	}
	char** store = malloc(512 * sizeof(char*));	//allocates memory for entire storage
	for(int i = 0; i < arguments; i++){
		store[i] = malloc(sizeof(char) * arguments); //allocates memory for each argument
	}						     //stored in the storage
	char* space = strtok(input, " ");
	int temp = 0;
	while(space != NULL){
		strcpy(store[temp], space);
		space = strtok(NULL, " ");
		temp++;
	}
	store[temp] = NULL;
	return store;
}


void freeWords(char** w){			//helper function created because of repeated use
	for(int i = 0; i < arguments; i++){     //throughout file
		free(w[i]);			//frees the memory of each argument stored
	}
}


void execute(char* str){
	char** words = getWords(str);
	int pid;
	if(strcmp(words[0], "exit") == 0){	//checks if user wants to exit
		printf("Exiting shell...\n");
		freeWords(words);
		free(words);
		exit(0);
	} else {
		if((pid = fork()) <0){
			printf("Error while forking, exiting...\n");
			freeWords(words);
			free(words);
			exit(1);
		} else if(pid > 0) {
			wait(NULL); 		//waits for termination of child process
		} else {
			int work;
			if((work = execvp(words[0], words)) < 0){
				printf("%s: Command Not Found.\n", words[0]);
				freeWords(words);
				free(words);
				exit(1);
			}
		}
	}
	freeWords(words); 		//final memory freeing
	free(words);
}

