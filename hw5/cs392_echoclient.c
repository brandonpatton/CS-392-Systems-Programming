/* I pledge my honor that I have abided by the Stevens Honor System.
 * Brandon Patton
 * cs392_echoclient.c
*/

#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char** argv){
	if(argc != 3){
		perror("Error: Expected 2 arguments.\n");
		exit(EXIT_FAILURE);
	}

	int sock;
	struct sockaddr_in echoserver;
	char buffer[1024];


	if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0){
		perror("Socket failure, Exiting.\n");
		exit(EXIT_FAILURE);
	}
	memset(&echoserver, 0, sizeof(echoserver));
	echoserver.sin_family = AF_INET;
	echoserver.sin_addr.s_addr = inet_addr(argv[1]); //Ip address
	echoserver.sin_port = htons(atoi(argv[2])); //Port
	
	//Connect to server
	if(connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver)) < 0){
		perror("Connection failed, Exiting.\n");
		exit(EXIT_FAILURE);
	} else {
		printf("Connected. Type your message:\n");
		fgets(buffer, sizeof(buffer), stdin); 
		buffer[strlen(buffer)-1] = '\0'; 
		printf("Sending message: %s\n", buffer);
		
		//Send message
		if(send(sock, buffer, strlen(buffer), 0) == -1){
			perror("Error sending, Exiting.\n");
			exit(EXIT_FAILURE);
		}
		memset(buffer, 0, sizeof(buffer));

		if(recv(sock, buffer, 1024-1, 0) == -1){
			perror("Error receiving, Exiting.\n");
			exit(EXIT_FAILURE);
		}
		//Message recieved, print to standard output
		printf("Received message: %s\n", buffer); 
		fflush(stdout);
		close(sock);
	}
	return 0; 
}
