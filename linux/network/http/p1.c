#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IP "61.147.124.120"
#define PORT 80
#define BUF_SIZE 2048

int main(int argc, char **argv) {
	int sockfd;
	struct sockaddr_in servaddr;
	char sendBuf[4096], postData[4096];
	char recvBuf[BUF_SIZE], *str;
	char buf[128];

	socklen_t len;
	fd_set t_set1;
	struct timeval tv;

	//创建套接字
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket:");
		return -1;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	//IP地址转换
	if(inet_pton(AF_INET, IP, &servaddr.sin_addr) <= 0) {
		perror("inet_pton:");
		return -1;
	}
	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connect:");
		return -1;
	}
	printf("成功连接\n");
	memset(postData, 0, 4096);
	strcat(postData, "qqCode=287101329");
	sprintf(buf, "%d", strlen(postData));

	memset(sendBuf, 0, 4096);
	//strcat(sendBuf, "GET / HTTP/1.1\n");
	strcat(sendBuf, "POST /webservices/qqOnlineWebService.asmx/qqCheckOnline HTTP/1.1\n");
	strcat(sendBuf, "Host: www.webxml.com.cn\n");
	strcat(sendBuf, "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:74.0) Gecko/20100101 Firefox/74.0\n");
	strcat(sendBuf, "Accept-Language: en-US,en;q=0.5\n");
	strcat(sendBuf, "Pragma: no-cache\n");
	//strcat(sendBuf, "Content-Type: text/html\n");
	strcat(sendBuf, "Content-Type: application/x-www-form-urlencoded\n");
	strcat(sendBuf, "Content-Length: ");
	strcat(sendBuf, buf);
	strcat(sendBuf, "\n\n");
	strcat(sendBuf, postData);
	strcat(sendBuf, "\r\n\r\n");
	printf("%s\n", sendBuf);
	int sendLen = write(sockfd, sendBuf, strlen(sendBuf));
	if(sendLen < 0) {
		printf("Send data fail!\n");
		return -1;
	}else {
		printf("Send data successful\n");
	}

	FD_ZERO(&t_set1); //清空t_set1与所有文件句柄的联系
	FD_SET(sockfd, &t_set1); //建立文件句柄sockfd与t_set1的联系

	while(1) {
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		switch(select(sockfd + 1, &t_set1, NULL, NULL, &tv)) {
			case -1: {
				close(sockfd);
				printf("select error:");
				return -1;
			} break;
			case 0: {
				//printf("timeout\n");

			} break;
			default: {
				memset(recvBuf, 0, BUF_SIZE);
				int len = read(sockfd, recvBuf, BUF_SIZE);
				if(0 == len) {
					close(sockfd);
					printf("disconnect \n");
					return -1;
				}
				printf("%s\n", recvBuf);
			}
		}
	}

	close(sockfd);

	return 0;
}
