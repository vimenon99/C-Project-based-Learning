#include <stdio.h>
#include <stdlib.h>     
#include <string.h>    
#include <sys/socket.h> 
#include <arpa/inet.h>   
#include <unistd.h>     


int main()
{
    int server_fd, client_fd; /*file descriptors for server and client sockets*/
    struct sockaddr_in server_addr, client_addr; /*structure for server and client address:ports*/
    socklen_t client_len = sizeof(client_addr); /*size of accepted client address*/
    char buffer[1024] = {0}; /*char array for messages*/

    server_fd = socket(AF_INET, SOCK_STREAM, 0); /*just means socket addr is IPV4 family, tcp socket, tcp protocol by default*/
    server_addr.sin_family = AF_INET; /*must match socket family*/
    server_addr.sin_addr.s_addr = INADDR_ANY; /*listen on local interface or all interface*/
    server_addr.sin_port = htons(65432); /*port number -> big endian format*/

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)); /*assigned socket to specific IP + Port*/
    listen(server_fd, 1); /*setting limit to connection and basically listening for any inbounf traffic*/
    printf("I Am Listening...\n");

    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    printf("Client Connected!\n");

    while (1){
        memset(buffer, 0, sizeof(buffer)); /*reset or clear buffer before every new message*/
        int bytes = recv(client_fd, buffer, sizeof(buffer),0); /*receive data from client */
        if (bytes<=0){
            break; /*disconnect if bytes -ve or 0*/
        }
        printf("Client: %s\n", buffer);
        send(client_fd, buffer, strlen(buffer), 0); 
    }/*echi same data back to client*/

    close(client_fd); /*closing connections both ways*/
    close(server_fd); /*closing connections both ways*/

    return 0;

}
