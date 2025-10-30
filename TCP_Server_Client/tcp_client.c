#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
	int sock; //socket initialize
	struct sockaddr_in server_addr; //server addr to bind ip and port
	char buffer[1024]= {0};
	
	sock = socket(AF_INET, SOCK_STREAM, 0); //tcp socket with ipv4
	server_addr.sin_family= AF_INET;
	server_addr.sin_port = htons(65432);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)); //conect to listening port at the server address
	
	while(1) {
		printf("You: ");
		fgets(buffer, sizeof(buffer), stdin); //get input message
		buffer[strcspn(buffer, "\n")] = 0; //remove new line
		
		send(sock, buffer, strlen(buffer), 0); //send message
	
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}
	
		memset(buffer, 0, sizeof(buffer)); //empty buffer
		recv(sock, buffer, sizeof(buffer), 0); //receive echoed message from server 
		printf("Server: %s\n", buffer); 
	}
	close(sock); //close connection
	return 0;
	}
	
