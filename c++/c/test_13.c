#include <stdio.h>
void Define_Undef()
{
	#define A "Hello"
	printf(A);
	#undef A
	#define A " World\n"
	printf(A);
}
void Define_Compare()
{
	#define CMP(a,b) (a>b?a:b)
	printf("MAX: %d",CMP(1,2));

}
void If_Endif_Elif()
{	
	#define TURE 1
	#define FALSE 0
	#define MAX(num1,num2) (num1>num2?TURE:FALSE)
	#define NUM 1
	#if NUM
	printf("Hello!\n");
	#endif
	#undef NUM
	#define NUM1 1
	#define NUM2 2
	#if MAX(NUM1,NUM2)
	printf("%d > %d \n",NUM1,NUM2);
	#elif !(MAX(NUM1,NUM2))
	printf("%d < %d\n",NUM1,NUM2);
	#endif
}
void Ifdef_Else_Endif()
{
//	#define IF
	#ifdef IF
	printf("IF has defined\n");
	#else
	printf("IF has not defined\n");
	#endif
}
void main()
{
	//Define_Undef();
	//Define_Compare();
	//If_Endif_Elif();
	Ifdef_Else_Endif();
}
