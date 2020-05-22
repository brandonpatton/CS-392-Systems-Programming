/* I pledge my honor that I have abided by the Stevens Honor System. 
 * Brandon Patton
 * CS392 Midterm
*/


/* Compares strings s1 and s2. Returns -1 if the value at an index in s1 has a lower ascii
 * value than the value at the same index in s2, returns 1 if the value at an index in s1 has a
 * higher ascii value than the value at the same index in s2. Returns 0 if all corresponding 
 * values have the same ascii value. 
*/
int cs392_strcmp(char *s1, char *s2){
	int i = 0;
	char it = s1[i];
						//Iterates through s1 and compares each value to
						//the corresponding values in s2. Return value 
						//is the same as what's described in the top comment
	while(it != '\0') {
		if((unsigned char)s1[i] < (unsigned char)s2[i]) {
			return -1;
		}
		if((unsigned char)s1[i] > (unsigned char)s2[i]) {
			return 1;
		} else {
			i++;
			it = s1[i];
		}
	}
		//Checks the last value in each string and has the same return behavior as what's 
		//described in the top comment.
	if((unsigned char)s1[i] < (unsigned char)s2[i]) {
			return -1;
		}
		if((unsigned char)s1[i] > (unsigned char)s2[i]) {
			return 1;
		} else {
			return 0;
		}
}
