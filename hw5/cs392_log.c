/* I pledge my honor that I have abided by the Stevens Honor System
 * Brandon Patton
 * cs392_log.c
 */

#include "cs392_log.h"

void cs392_socket_log(char *ip, int port){
    FILE *fp = fopen("cs392_socket.log", "a");
    if(fp == NULL){
        perror("Error opening file.\n");
        exit(1);
    } else {
        fprintf(fp,"IP address: %s, Port: %d\n", ip, port);
    }
    fclose(fp);
}
