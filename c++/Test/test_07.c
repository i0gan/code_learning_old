#include <stdio.h>	//print Jin TA
void Print(int line,char sign){
	for(int i_1=line;i_1>0;i_1--)
	{
		for(int i_2=0;i_2<(i_1-1);i_2++)
			printf(" ");
		for(int i_3=0;i_3<(2*(line-i_1+1)-1);i_3++)
			printf("%c",sign);
		printf("\n");
	}
}
int main(){
	Print(25,'$');
	return 0;
}
