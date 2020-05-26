#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
/*
#include <pthread.h>

       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
		arg1: 传入储存thread_id的地址
		arg2: 属性, 为NULL时为默认属性
		arg3: 将要运行的函数地址(要为静态函数)
		arg4: 传入的参数
		If attr is NULL, then the thread is created with default attributes.
*/

void print_id(char *arg) {
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid: %lx tid: %lx\n",arg, pid, tid);
}

void *thread_fun(void *arg) {
	print_id(arg);
	int a;
	printf("\n stack: %p\n", &a);
	return (void*)0;
}


int main(void) {
	pthread_t ntid;
	int err;
	err = pthread_create(&ntid, NULL, thread_fun,  "new thread");
	if(err != 0) {
		printf("create new thread failed\n");
		return -1;
	}
	print_id("main_thread");
	int a;
	printf("\n stack: %p\n", &a);
	sleep(2);

	return 0;
}
