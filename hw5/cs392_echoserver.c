/* I pledge my honor that I have abided by the Stevens Honor System
 * Brandon Patton
 * cs392_echoserver.c
*/

#include "cs392_log.h"

int main(int argc, char** argv){
	if(argc != 2){		//input checking
		perror("Error: Expected 1 argument.\n");
		exit(EXIT_FAILURE);
	}

	char buffer[1024];	
	int s_sock, c_sock;	//start of socket process
	struct sockaddr_in echoserver, echoclient;
	int clientlen = sizeof(struct sockaddr_in);

	if((s_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
		perror("Socket failure, Exiting.\n");
		exit(EXIT_FAILURE);
	}

	memset(&echoserver, 0, sizeof(echoserver));
	echoserver.sin_family = AF_INET;
	echoserver.sin_addr.s_addr = htonl(INADDR_ANY);
	echoserver.sin_port = htons(atoi(argv[1])); //get port

	if(bind(s_sock, (struct sockaddr*) &echoserver, sizeof(echoserver)) < 0){
		perror("Bind failure, Exiting.\n");
		exit(EXIT_FAILURE);
	}

	if(listen(s_sock, 5) < 0){  //MAXPENDING = 5	
		perror("Listen failure, Exiting.\n");
		exit(EXIT_FAILURE);

	} else {
		printf("Listening for connections...\n");
	}

	clientlen = sizeof(struct sockaddr_in);

	while(1){
		if( (c_sock = accept(s_sock, (struct sockaddr *) &echoclient, &clientlen)) == -1){
			perror("Error accepting, Exiting.\n");
			exit(EXIT_FAILURE);
		} else {
			printf("Client Connection, IP Address: %s, Port: %d\n", inet_ntoa(echoclient.sin_addr), ntohs(echoclient.sin_port));
			fflush(stdout);
			//logging occurs
			cs392_socket_log(inet_ntoa(echoclient.sin_addr), ntohs(echoclient.sin_port));  
			memset(buffer, 0, sizeof(buffer));
			
			if(recv(c_sock, buffer, 1023, 0) == -1){
				perror("Error receiving message, Exiting.\n");
				exit(EXIT_FAILURE);
			}
			
			if(send(c_sock, buffer, strlen(buffer), 0) == -1){
				perror("Error sending message, Exiting.\n");
				exit(EXIT_FAILURE);
			}

			printf("Sent message: %s\n", buffer);  //One message echoed, then closed
			close(c_sock);	
		}
	}
	return 0;
}
