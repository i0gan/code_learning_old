#include<stdio.h>//使用递归函数来实现1+2+3+4+....+100
int Plus(int num){
	if(num==1){
		return ;
	}
	Plus(num-1);
}
int main(void){
	printf("Please input a number to calculate\n");
	scnaf("%d",&num);
	Plus(num);
	return 0;
}
