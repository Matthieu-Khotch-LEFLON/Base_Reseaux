#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file> <server_name> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    
    char *file = argv[1];
    char *server_name = argv[2];
    int port = atoi(argv[3]);


    printf("Vous avez demandé le fichier %s, sur le serveur %s qui est sur le port %d\n", file, server_name, port);

    return 0;
}
