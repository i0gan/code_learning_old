#include<stdio.h>
int main(void){		//实现斐波那契数列---2019.7.20
	int arr_length=0;
	int i_1=1,i_2=1,i_3=2;
	int i=0;
	printf("Input a array length\n");
	scanf("%d",&arr_length);
	if(arr_length==3)
		printf("%d %d %d\n",i_1,i_2,i_3);
	if(arr_length==2)
		printf("%d %d\n",i_1,i_2);
	if(arr_length==1)
		printf("%d\n",i_1);
	if(arr_length>=4)
	{	
		printf("%d %d %d",i_1,i_2,i_3);
		while(i<(arr_length-3))
		{
			i_1=i_2;
			i_2=i_3;
			i_3=i_1+i_2;
			printf(" %d",i_3);
			i++;
		}
		printf("\n");
	}
	if(arr_length<=0)
	printf("There is a error!\n");
	return 0;
}
