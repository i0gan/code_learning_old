#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if(argc <= 2) {
		printf("Usage: %s [ip] [port]\n", basename(argv[0]));
		return 1;
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in address;
	bzero(&address, sizeof(address));

	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);

	int sock = socket(PF_INET, SOCK_STREAM, 0);
	assert(sock >= 0);

	int ret = bind(sock, (struct sockaddr *)&address, sizeof(address));
	if(-1 == ret) {
		perror("bind");
		return 1;
	}

	ret = listen(sock, 5);
	assert(ret != -1);

	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int c_fd = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len);
	if(c_fd == -1) {
		perror("accept::");
	}else {
		char remote[INET_ADDRSTRLEN];
		printf("connected with ip: %s and port %d\n",
		inet_ntop(AF_INET, &client_addr.sin_addr, remote, INET_ADDRSTRLEN),
		ntohs(client_addr.sin_port));

		close(c_fd);
	}

	return 0;
}
