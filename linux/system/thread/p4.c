#include <stdio.h>
#include <pthread.h>
#include <errno.h>

struct Value {
	int thread;
	int value;
	int lock;
};

void *fun(void *arg) {
	struct Value *value = (struct Value *)arg;

	while(value->value < 50) {
		if(value->lock == 0 && value->thread == 1) {
			value->lock = 1;
			printf("child: %d\n", value->value);
			value->value += 1;
			value->thread = 0;
			value->lock = 0;
		}
	}

	return (void*)0;
}

int main(void) {
	struct Value value;
	value.value = 0;
	value.lock = 0;
	value.thread = 0;

	int err, retval;
	pthread_t tid;
	err = pthread_create(&tid, NULL, fun, &value);
	if(err != 0) {
		perror("thread_create:");
		return -1;
	}
	while(value.value < 50) {
		if(value.lock == 0 && value.thread == 0) {
			value.lock = 1;
			printf("main_thread: %d\n", value.value);
			value.value += 1;
			value.thread = 1;
			value.lock = 0;
		}
	}

	pthread_exit(0);
	return 0;
}
