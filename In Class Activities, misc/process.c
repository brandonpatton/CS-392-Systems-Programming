/* I pledge my honor that I have abided by the Stevens Honor System
 * Brandon Patton
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static void hdl (int sig, siginfo_t *siginfo, void *context){
	if (sig == SIGINT){
		printf("received SIGINT \n");
	}
}

int main(){

	struct sigaction act;

	memset (&act, 0, sizeof(act));

	act.sa_sigaction = &hdl;
	
	act.sa_flags = SA_SIGINFO | SA_RESETHAND;

	if (sigaction(SIGINT, &act,NULL)<0){
		perror("sigaction");
	}

	while(1){

	sleep(1);

	printf("Hellow\n");

  }
}
