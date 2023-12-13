# Base_Reseaux

## Question 1 :

```ruby

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file> <server_name> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    
    char *file = argv[1];
    char *server_name = argv[2];
    char *port = argv[3];


    printf("You have requested the file %s, on the server %s, which is on port %s\n", file, server_name, port);

    return 0;
}

```
![SCREENSHOT](Assets/TerminalQuestion1.png)


## Question 2 :

```ruby

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file> <server_name> <port> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    
    char *file = argv[1];
    char *server_name = argv[2];
    char *port = argv[3];


    printf("You asked for the file %s, on the server %s qwhich is on port %s \n", file, server_name, port);
    
    struct addrinfo hints;
    struct addrinfo *res;
    
    memset(&hints, 0, sizeof( struct addrinfo));
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_family = AF_INET;
    hints.ai_protocol = 0;
    
    int adress = getaddrinfo(server_name, port, &hints, &res);
    
    if (adress == -1){
		perror("getaddrinfo");
		return(EXIT_FAILURE);
	}
	
    printf("The server adress is  %d \n",adress);
    
    return 0;
}

```
![SCREENSHOT](Assets/TerminalQuestion2.png)
