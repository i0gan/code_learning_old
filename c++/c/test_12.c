#include <stdio.h>
int main()
{
	int a=123456;
	int b=0;
	printf("Please you input password!\n");
	scanf("%d",&b);
	if(a==b)
	{
		printf("Congratulations!\n");
	}else
	{
		printf("Sorry! Your passwd is wrong!\n");
	}
	getchar();
	return 0;
}
