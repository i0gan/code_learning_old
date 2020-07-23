#include <unistd.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

void my_init(void) __attribute__((constructor));// 告诉gcc把这个函数扔到init_section
void my_fini(void) __attribute__((destructor)); // 告诉gcc把这个函数扔到fini_section

void my_init(void) {
	printf("init ...\n");
}
void my_fini(void) {
	printf("fini ...\n");
}

int main(void) {
	void *dl;
	void *fun_run;
	void (*run)();
	//(void (*)())fun_run;


	dl = dlopen("lib/lib.so", RTLD_LAZY);

	if(dl == NULL) {
		printf("open fail!\n");
		exit(-1);
	}

	run = (void (*)()) dlsym(dl, "run");
	run();

	dlclose(dl);

	return 0;
}
