/* I pledge my honor that I have abided by the Stevens Honor System
 * Brandon Patton 
 * cs392_log.h
 */

#ifndef CS392_LOG_H
#define CS392_LOG_H

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

void cs392_socket_log(char*, int);


#endif 
