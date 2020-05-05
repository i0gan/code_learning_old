#include <stdio.h>
char* Order(char* arr,int length)	//桶排序
{
	int max=0;
	int i=0;
	printf("%d",length);
	while(i<length)
	{
		if(*(arr+i)>max)
		{
			max=*(arr+i);
		}
		i++;
	}
	printf("%d\n",max);
}
int main()
{
	char arr[10]={1,34,32,34,11,3,35,67,89,22};
	Order(arr,sizeof(int));
	return 0;
}
