#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct Student {
	int age;
	char name[64];
};

void *thread_fun(void *std) {
	printf("age: %d name %s\n", ((struct Student *)std)->age, ((struct Student *)std)->name);
	return (void*)0;
}

int main(int argc, char **argv) {

	if(argc > 1) {
		if(!strcmp(argv[1], "exit")) {
			return 0;
		}
	}
	struct Student std;
	std.age = 16;
	strcpy(std.name, "Hello World");
	pthread_t tid;
	int err;
	err = pthread_create(&tid, NULL, thread_fun, &std);
	if(err != 0) {
		printf("create trhead fail!\n");
		return -1;
	}
	int retval;

	pthread_exit(&retval); //保证子线程能够顺利执行
	printf("main thread exit\n");

	return 0;
}
