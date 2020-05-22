/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * Assignment 3
 */
#include "cs392_exec.h"
#include "cs392_log.h"  	//change these to header names later
#include "cs392_signal.h"
#include <stdlib.h>
#define BUFF 512

int shell(){
	char buffer[BUFF];
	size_t input;
	int i;

	while(1){
		signalH();  			//signal function from cs392_signal.c
		printf("cs392_shell $: ");
		fflush(stdout);
		if((input = read(0, buffer, BUFF - 1)) < 0){	//read in cmd line inputs
			if(errno == EINTR){
				continue;	//ensures that shell continually waits for input
			} else { 			
				perror("Error reading in \n");
				exit(1);
			}
		}
		buffer[input - 1] = '\0';
		logH(buffer);			//log function from cs392_log.c
		execute(buffer);		//executing function from cs392_exec.c
	}					//exec.c also handles memory freeing
	return 0;
}

int main(){
	shell(); 		
	return 0;
}
