#include <semaphore.h> //使用信号量
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
/*
	信号量
	#include <semaphore.h>
	采用信号量实现同步机制
	int sem_init(sem_t *sem, int pshared, unsigned int val);
	成功返回0, 失败返回EOF
	sem:    为指定要初始化的信号两对象
	pshared:为0时代表线程之间通信, 1代表进程间通信
	val 信号量初值

	信号量 P / V 操作
	int sem_wait(sem_t *sem); //P操作, 申请资源, 可能会发生阻塞
	int sem_post(sem_t *sem); //V操作, 释放资源, 不会发生阻塞

	成功时返回0, 失败时返回EOF
	sem指向要操作的信号量对象

*/
char buf[512];
sem_t sem_r, sem_w;
void *thread_fun(void *arg) {
	while(1) {
		sem_wait(&sem_r);
		printf("Your input: %s\n", buf);
		sem_post(&sem_w);
	}
}

int main(void) {
	pthread_t tid;
	if(sem_init(&sem_r, 0, 0) != 0) {
		perror("sem_init(): ");
		return -1;
	}

	if(sem_init(&sem_w, 0, 0) != 0) {
		perror("sem_init(): ");
		return -1;
	}

	if(pthread_create(&tid, NULL, thread_fun, NULL) != 0) {
		perror("pthread_create(): ");
		return -1;
	}

	printf("Input something, 'quit' to exit program\n");
	do {
		fgets(buf, 512, stdin);
		sem_post(&sem_r);
		sem_wait(&sem_w);
	}while(strncmp(buf, "quit", 4) != 0);

	return 0;
}
