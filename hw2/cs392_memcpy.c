/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * CS392 Assignment 2
 * memcpy.c
 */
#include "cs392_string.h"

void *cs392_memcpy(void *dst, void *src, unsigned num){
	//Copies contents of src to the memory pointed to by dst.
	char *ref_d = dst; 		//Pointer casting
	char *ref_s = src;
	for(int i = 0; i < num; i++){
		ref_d[i] = ref_s[i];	//Copying
	}
	return dst;
}
