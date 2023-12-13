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
