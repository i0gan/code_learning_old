#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

//linux 默认个人邮箱地址是: /var/spool/mail用户登录名称
#define MAIL "/var/spool/mail/logan/a.com"
#define SLEEP_TIME 2

int main(void) {
	pid_t pid;
	if(-1 == (pid = fork())) {
		printf("Fork error: %s\n", strerror(errno));
		exit(1);
	}else if(pid > 0)
	while(1);

	if(kill(getppid(), SIGTERM) == -1){ //杀掉父进程
		printf("Kill parent error: %s\n", strerror(errno));
		exit(1);
	}
	int mailfd;
	while(1) {
	if(-1 != (mailfd = open(MAIL, O_RDONLY))) {
		fprintf(stderr,"%s", "\007");
		close(mailfd);
	}
	sleep(SLEEP_TIME);
	}

	return 0;
}
