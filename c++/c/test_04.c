#include <stdio.h>
int main(void)
{
	char line[10];
	FILE* source_file=fopen("test_01.c","r");
	char* end;
	if(!source_file)
	{
		printf("Opne fali!");
		return 0;
	}
	while(1)
	{
	end=fgets(line,sizeof(line),source_file);
	if(end)
	{
	 printf("%s",line);
	}
	else break;
	}

	return 0;
}
