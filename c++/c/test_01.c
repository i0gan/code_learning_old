#include <stdio.h>
int main()
{
	const int ROWS=15;
	const int CHARS=15;
	int row;
	char ch;
	for (row=0;row<ROWS;row++)
	{
		for(ch=('a'+row);ch<('a'+CHARS);ch++)
		{
			printf("%c",ch);
		}
		printf("\n");
	}
	return 0;
}
