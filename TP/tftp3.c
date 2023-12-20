#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 128

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file> <server_name> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    
    char *file = argv[1];
    char *server_name = argv[2];
    char *port = argv[3];


    printf("You asked for the file %s, on the server %s which is on port %s\n", file, server_name, port);
    
    struct addrinfo hints;
    struct addrinfo *res;
    
    memset(&hints, 0, sizeof( struct addrinfo));
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_family = AF_INET;
    hints.ai_protocol = IPPROTO_UDP;
    
    int adress;
    if((adress = getaddrinfo(server_name, port, &hints, &res)) == -1){
		perror("getaddrinfo error");
		exit(EXIT_FAILURE);
	}


    int sock;
    if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol))==-1){
		perror("socket error");
		exit(EXIT_FAILURE);
	}
	
	// RRQ's request
	char buffer[BUFSIZE];
	memset(buffer, 0, BUFSIZE);
	buffer[1] = 1;
	strcpy(buffer+2, argv[1]);
	size_t padding = strlen(buffer+2);
	strcpy(buffer+2+padding+1,"octet");
	size_t padding2 = strlen(buffer+3+padding);
	
	if (sendto(sock, buffer, padding+padding2+4, 0, res->ai_addr, res->ai_addrlen) == -1){
		perror("send RRQ");
		exit(EXIT_FAILURE);
	}
    
    int n_bytes;
	if ((n_bytes = recvfrom(sock, buffer, BUFSIZE, 0, res->ai_addr, &res->ai_addrlen)) == -1){
		perror("receive DATA");
		exit(EXIT_FAILURE);
	}
	
	// Check if the received packet is a DATA packet
	if (buffer[1] != 3) {
		fprintf(stderr, "Unexpected packet received. Expected DATA packet.\n");
		exit(EXIT_FAILURE);
	}
	
	// Extract data from the received packet (excluding the header)
	size_t data_length = n_bytes - 4;
	printf("Received Data: %.*s\n", (int)data_length, buffer + 4);
	
	// Simulate sending an ACK packet
	char ackPacket[4] = {0, 4, buffer[2], buffer[3]};
	if (sendto(sock, ackPacket, 4, 0, res->ai_addr, res->ai_addrlen) == -1) {
		perror("send ACK");
		exit(EXIT_FAILURE);
	}
	
	close(sock);
	return 0;
}
