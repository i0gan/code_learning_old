#include <stdio.h>
#include "add.h"
#include "sub.h"
int main()
{
	int a=10,b=12;
	float x=1.23456,y=9.876543;
	printf("int a+b = %d\n",add_int(a,b));
	printf("int a-b = %d\n",sub_int(a,b));
	printf("float x+y = %f\n",add_float(x,y));
	printf("float x-y = %f\n",sub_float(x,y));
	printf("OK!!!!\n");
	return 0;
}
