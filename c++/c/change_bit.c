#include <stdio.h>
#define print printf("%x\n",ch_bit);
void check_bit(unsigned int ch_bit,int lenth)
{
	unsigned int see_bit=ch_bit;
	printf("Your number bit is:");
	for(int i=0;i<lenth;i++)
	{
		see_bit=see_bit>>(lenth-1-i);
		see_bit=see_bit%2;
		printf("%x",see_bit);
		see_bit=ch_bit;          
       	}
	printf("\n");
}
void change_bit(char* ch,int lenth)
{
	int bit=0;
	unsigned char see_bit=*ch;
	unsigned char ch_bit=*ch;
	unsigned char tem_bit_1=0x1;
	unsigned char tem_bit_2=0xFF;
	check_bit(*ch,lenth);
	printf("\nWhat bit do you wanna change? 1-8\n");
	scanf("%d",&bit);

	see_bit=see_bit<<(lenth-(bit-1)-1); // see the bit also can use -> see_bit=see_bit>>bit;see_bit=see_bit%2;
	see_bit=see_bit>>(lenth-1);

	tem_bit_2=tem_bit_2^(tem_bit_1<<(bit-1)); //move bit
	if(see_bit==0)
	{
		ch_bit=ch_bit|(~tem_bit_2);
	}else
	{
		ch_bit=ch_bit&tem_bit_2;
	}
	*ch=ch_bit;
	printf("Your number has changed as:\n");
	check_bit(*ch,lenth);
}
int main()
{
	unsigned char ch=0x81;
	change_bit(&ch,8);	
}
