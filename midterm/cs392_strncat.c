/* I pledge my honor that I have abided by the Stevens Honor System. 
 * Brandon Patton
 * CS392 Midterm
*/

/* Appends the src string to the dest string. Overwrites the terminating null byte at the
 * end of dest with the first byte to append. Adds a terminating null byte after the appending.
 */
char *cs392_strncat(char *dest, char *src, unsigned n){
	int size = 0, i = 0;
	// Iterates through dest to get the length. 
	while(dest[size] != '\0') {
		size++;
	}
	//Iterates through src and appends the values to the end of dest.
	for(; i<n; size++,i++){
		dest[size] = src[i];
	}
	dest[size] = '\0';
	return dest;
}
