#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static bool stop = false;
static void handle_term(int sig) {
	stop = true;
}

int main(int argc, char **argv) {
	signal(SIGTERM, handle_term);
	if(argc <= 3) {
		printf("Usage: %s ip_address port_number backlog\n", basename(argv[0]));
		return 1;
	}
	const char *ip = argv[1];
	int port = atoi(argv[2]);
	int backlog = atoi(argv[3]);

	int sock = socket(PF_INET, SOCK_STREAM, 0);
	assert(sock >= 0);
	struct sockaddr_in address;
	bzero(&address, sizeof(address)); //清空为0
	address.sin_family = AF_INET;

	//inet_pton是一个IP地址转换函数,
	//可以在将IP地址在“点分十进制”和“二进制整数”之间转换
	//而且inet_pton和inet_ntop这2个函数能够处理ipv4和ipv6
	
	inet_pton(AF_INET, ip,  &address.sin_addr);
	address.sin_port = htons(port); //转化为网络字节序

	//绑定
	int ret = bind(sock, (struct sockaddr *)&address, sizeof(address));
	assert(-1 != ret);

	ret = listen(sock, backlog);
	assert(-1 != ret);

	//通过系统发送信号来终止程序
	while(!stop) {
		sleep(1);
	}

	close(sock);
	printf("End program\n");

	return 0;
}
