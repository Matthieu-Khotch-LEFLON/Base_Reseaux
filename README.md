# Base_Reseaux

## Question 1 :

```ruby

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /*Check if the correct number of command-line arguments is provided*/
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
    
    memset(&hints, 0, sizeof( struct addrinfo));	/* Initialize hints to zero and set desired socket options */
    hints.ai_socktype = SOCK_DGRAM;			/* Datagram socket (UDP) */
    hints.ai_family = AF_INET;				/* Use IPv4 */
    hints.ai_protocol = 0;				/* Use UDP protocol */
    
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



## Question 3 :

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
        fprintf(stderr, "Usage: %s <file> <server_name> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *file = argv[1];
    char *server_name = argv[2];
    char *port = argv[3];


    printf("You asked for the file %s, on the server %s which is on port %s\n", file, server_name, port);
    
    struct addrinfo hints;
    struct addrinfo *res;	/* Pointer to the result of getaddrinfo */
    
    memset(&hints, 0, sizeof( struct addrinfo));
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_family = AF_INET;
    hints.ai_protocol = IPPROTO_UDP;
    int adress = getaddrinfo(server_name, port, &hints, &res);			/* Obtain address information for the given server name and port */
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);	/* Create a socket using the obtained address information */
    
    
    
    if(adress == -1){
		perror("getaddrinfo error");
		exit(EXIT_FAILURE);
	}

	if (sock <0){
		perror("socket error");
		exit(EXIT_FAILURE);
	}
    
    return 0;
}
```

 
