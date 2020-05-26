#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_fun(void *arg) {
	if(!strcmp("1", (char *)arg)) {
		printf("new thread return \n");
		return (void *)1;
	}else if(!strcmp("2", (char *)arg)) {
		printf("new thread pthread_exit \n");
		pthread_exit((void*)2);
	}else {
		printf("new thread exit\n");
		exit(3);
	}
}

int main(int argc, char **argv) {
	int err;
	pthread_t tid;
	if(argc < 2) {
		printf("input arg\n");
		return 0;
	}
	err = pthread_create(&tid, NULL, thread_fun, argv[1]);
	if(err != 0) {
		printf("create new thread failed\n");
		return 0;
	}
	sleep(1);

	printf("main thread\n");
	return 0;
}
