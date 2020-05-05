#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <cstdlib>
#define SERVER_PORT 3456
using namespace std;
void shell() {
	int sock;
	struct sockaddr_in server_addr;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(SERVER_PORT);

	bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));	
	

	cout << "Waiting client..." << endl;
	listen(sock, 128);
	char *buf =(char *)malloc(0x1000);
	int text_len = 0;

	struct sockaddr_in client;	
	int client_sock;
	char client_ip[64];	
	socklen_t client_addr_len = sizeof(client);
		
	client_sock = accept(sock, (struct sockaddr *)&client, &client_addr_len);
	cout << "Successful connection!"
	<< endl
	<< "Client ip: " 
	<< "    port: "
	<< ntohs(client.sin_port)
	<< endl;	
	
	while(true) {
		text_len = read(client_sock, buf, 0x1000 - 1);
		if(text_len > 0){
			buf[text_len] = '\x00';
			cout << buf;

			fgets(buf, 0x200, stdin);
			if(!strcmp(buf, "exit")) {
				cout << "Closed connection" << endl;
				write(client_sock, "exit", 0x5);
				break;
			}
			write(client_sock, buf, strlen(buf) + 1);
		}	
	}
	close(client_sock);

}

int main(void) {
	setbuf(stdin, 0);
	setbuf(stdout, 0);
	shell();
	return 0;
}
