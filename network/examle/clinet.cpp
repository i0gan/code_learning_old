#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
#define SERVER_PORT 6666
#define SERVER_IP "127.0.0.1"

int main(int argc, char **argv) {
	int sockfd;
	int n;
	struct sockaddr_in serveraddr;
	char str[256] = "Hello You guys\n";
	if(argc < 2) {
		cout << "Usage: ./clinet [message]" << endl;	
		fputs("Input error! \n", stderr);
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serveraddr, 0, sizeof(struct sockaddr_in));
	serveraddr.sin_family = AF_INET;

	inet_pton(AF_INET, SERVER_IP, &serveraddr.sin_addr);
	serveraddr.sin_port = htons(SERVER_PORT); //转化为网络字节顺序
	
	connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
	write(sockfd, argv[1], strlen(argv[1]));
	n = read(sockfd, str, sizeof(str) - 1);
	if(n > 0) {
		str[n] = '\0';
		cout << str;
	}else {
		perror("error");
	}	

	cout << endl << "finished" << endl;
	close(sockfd);
	return 0;
}

