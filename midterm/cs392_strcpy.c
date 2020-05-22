/* I pledge my honor that I have abided by the Stevens Honor System. 
 * Brandon Patton
 * CS392 Midterm
*/
 
//Copies the string pointed to by src, including the null byte, to the buffer pointed to by dest.
char* cs392_strcpy(char *dest, char *src) {
	int i = 0;
	char iter = src[i];
					//Iterates through the string pointed to by src
					//and sets corresponding indices in dest to the values in src. 
	while(src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return dest;
}
