/* I pledge my honor that I have abided by the Stevens Honor System
 * Brandon Patton
 * Assignment 3
 */

#include "cs392_signal.h"

void hdl(int sig, siginfo_t *siginfo, void *context){
	//handles the cases where the user pressed ctrl + z or ctrl + c
	if(sig == SIGINT){
		printf("\nReceived SIGINT (CTRL + C pressed), please type 'exit' to exit. \n");
	}
	if(sig == SIGTSTP){
		printf("\nReceived SIGTSTP (CTRL + Z pressed), please type 'exit' to exit. \n");
	}
}

void signalH(){
	struct sigaction act;
	memset (&act, 0, sizeof(act));

	act.sa_sigaction = &hdl;
	act.sa_flags = SA_SIGINFO | SA_RESETHAND;

	if(sigaction(SIGINT, &act, NULL) < 0){
		perror("sigaction");
	}
	if(sigaction(SIGTSTP, &act, NULL) < 0){
		perror("sigaction");
	}
}
