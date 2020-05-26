#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	pid_t pid;
	pthread_t tid;
	//获取进程id
	pid = getpid();

	//获取线程id
	tid = pthread_self();

	printf("pid: %x pthread_id: %lx\n", pid, tid);
	return 0;
}
