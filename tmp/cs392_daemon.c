/* I pledge my honor that I have abided by the Stevens Honor System
 * Brandon Patton
 * cs392 daemon process quiz
 */


#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(void){
	pid_t pid, sid;
	
	pid = fork();
	if(pid < 0){
		exit(EXIT_FAILURE);
	}
	if(pid > 0){
		exit(EXIT_SUCCESS);
	}
	umask(0);
	
	sid = setsid();
	if(sid < 0){
		exit(EXIT_FAILURE);
	}
	
	if((chdir("/tmp")) < 0){
		exit(EXIT_SUCCESS);
	}
	
	FILE *fp;
	fp = fopen("cs392_daemon.log", "w");
	if(fp == NULL){
		printf("Error creating file");
	}	

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while(1){
		sleep(2);
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		fprintf(fp, "%s", asctime(tm));  
		fflush(fp);
	}
	
	fclose(fp);
	
	exit(EXIT_SUCCESS);
}

