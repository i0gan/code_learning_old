#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread_fun_1() {
	printf("I'm thread 1\n");
	return (void*)1;
}

void* thread_fun_2() {
	printf("I'm thread 2\n");
	//pthread_detach(pthread_self()); //分离线程,会导致pthread_join失败
	pthread_exit((void *)2);

	return (void*)2;
}


int main(void) {
	int err_1, err_2;
	pthread_t tid_1, tid_2;
	void *rval_1, *rval_2;

	err_1 = pthread_create(&tid_1, NULL, thread_fun_1, NULL);
	err_2 = pthread_create(&tid_2, NULL, thread_fun_2, NULL);
	if(err_1 || err_2) {
		printf("create new thread failed!\n");
		return 0;
	}
	printf("I'm main thread\n");
	printf("join1 rval is %d\n", pthread_join(tid_1, &rval_1));
	printf("join2 rval is %d\n", pthread_join(tid_2, &rval_2));

	printf("thread 1 exit code is %d\n", rval_1);
	printf("thread 2 exit code is %d\n", rval_2);
	printf("I'm main thread\n");
}
