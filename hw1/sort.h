/* Assignment 1 CS 392 Systems
 * February 15, 2019
 * I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
*/

#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef unsigned int uint;   //Established here for convenience.
typedef unsigned long ulong;

uint* rArray(char*);
int compare(const void*, const void*);
void out(uint*, char*);

#endif
