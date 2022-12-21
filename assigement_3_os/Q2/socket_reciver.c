#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#define SERVER_PATH "sock.server"
#define CLIENT_PATH "sock.client"
int main(void){
    int client_socket, rc, len;
    struct sockaddr_un server_socket_addr; 
    struct sockaddr_un client_socket_addr; 
    memset(&server_socket_addr, 0, sizeof(struct sockaddr_un));
    memset(&client_socket_addr, 0, sizeof(struct sockaddr_un));
    client_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    client_socket_addr.sun_family = AF_UNIX;   
    strcpy(client_socket_addr.sun_path, CLIENT_PATH); 
    len = sizeof(client_socket_addr);
    unlink(CLIENT_PATH);
     bind(client_socket, (struct sockaddr *) &client_socket_addr, sizeof(client_socket_addr));
    server_socket_addr.sun_family = AF_UNIX;
    strcpy(server_socket_addr.sun_path, SERVER_PATH);
     connect(client_socket, (struct sockaddr *) &server_socket_addr, sizeof(client_socket_addr));
	char str[50][6] = {{0}};                                      
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 50; j++){
            str[j][i] = rand() % 26 + 65; 
			
        }
	
    }
	for (int i =1; i< 50;i++){
		printf("Data sent :%s\n",str[i]);
		send(client_socket, str[i-1], sizeof(str[i-1]), 0);
		sleep(100000);
		if (i%5==0&& i>0){
			printf("Index recieved :%d\n",i);
		}
	}
    close(client_socket);
    return 0;
}