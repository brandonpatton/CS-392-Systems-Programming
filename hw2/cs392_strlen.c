/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * CS392 Assignment 2
 * strlen.c
 */
#include "cs392_string.h"	

unsigned cs392_strlen(char *str){
	//Iterates through str while keeping a count 'i'. i represents the length str
	uint i = 0;
	while (str[i] != '\0'){
		i++;
	}
	return i;
}
