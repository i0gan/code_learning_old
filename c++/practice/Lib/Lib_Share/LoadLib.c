#include "./include/logan.h"
#include <dlfcn.h>
void Invoker()
{
	char Fun[]="Hello";
	char Dl[]="./lib/libHello.so";
	void (*Hello)();
	void* phandle;
	void *perr=NULL;
	phandle=dlopen(Dl,RTLD_LAZY);
	if(!phandle)
	{
		printf("Open hello.so fail!\n");
		return;
	}
	perr=dlerror();
	if(perr!=NULL)
	{
		printf("Something wrong!1\n");
		return;
	}
	if(!(Hello=dlsym(phandle,Fun)))
	{
		printf("Can't find Hello Funciton!\n");
		return;
	}
	perr=dlerror();
	if(perr!=NULL)
	{
		printf("Something Wrong!2\n");
		return;
	}
	Hello();
	dlclose(phandle);
}
int main()
{
	Invoker();
	return 0;
}
