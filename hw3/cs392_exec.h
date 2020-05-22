/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * Assignment 3
 */

#ifndef CS392_EXEC_H
#define CS392_EXEC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char** getWords(char*);
void execute(char*);

#endif

