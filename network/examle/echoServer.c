#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define SERVER_PORT 6666
int main(void) {
	int sock;  //信箱
	//AF_INET表示使用网络地址, SOCK_STREAM表示使用TCP协议
	sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_addr; //这个结构体,头文件中已经声明
	//清空标签
	bzero(&server_addr, sizeof(server_addr));
	//设置协议家族为网络协议	
	//htonl = host to net ,选择协议族为ipv4,
	server_addr.sin_family = AF_INET;
	//监听本地所有地址
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(SERVER_PORT); //绑定端口号
	//实现标签贴到信箱上
	bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

	listen(sock, 128); //同时的连接数量,同时来的信件接受多少封,这里为128
	
	//万事俱备,只等来信.
	printf("等待客户连接...\n");

	while(1) {
		struct sockaddr_in client;
		int client_sock ; //客户端
		char client_ip[64];
		char buf[256];
		int buf_len;
		socklen_t client_addr_len = sizeof(client);

		 client_sock = accept(sock, (struct sockaddr *)&client, &client_addr_len);
		//打印客户端地址和端口号	
		//转化网络字节序
		printf("client ip: %s\n port: %d\n", 
		inet_ntop(AF_INET, &client.sin_addr.s_addr, client_ip, sizeof(client_ip)),
		ntohs(client.sin_port));
		
		//读取数据
		buf_len = read(client_sock, buf, sizeof(buf) - 1);
		buf[buf_len] = '\x00';
		printf("接受到消息: %s\n", buf);
		for(int i = 0; i < buf_len; i++) {
				buf[i] = toupper(buf[i]);
		}	
		write(client_sock, buf, strlen(buf));
		printf("write[%s] finished!!!\n", buf);

		close(client_sock);
	}

	return 0;
}
