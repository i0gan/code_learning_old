#include <stdio.h>    //--------实现hannuota攻略程序
int hannuota(int n,char A,char B,char C)
{
	if(n==1){
		printf("Move %c to %c\n",A,C);
		return 0;
	}
	hannuota(n-1,A,C,B);
	printf("Move %c to %c\n",A,C);
	hannuota(n-1,B,A,C);

}
int main(void){
	int num=0;
	printf("输入塔的个数\n");
	scanf("%d",&num);
	hannuota(num,'A','B','C');
	return 0;
}

