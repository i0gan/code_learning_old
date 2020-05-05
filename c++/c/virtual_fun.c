#include <stdio.h>
class a
{
	int num;
public:
	a()
	{
		num='a';
	}
virtual  void print()
	{
		printf("%c\n",num);
	}
};
class b:public a
{
	int num;
public: 
	b()
	{
		num='b';
	}
	void print()
	{
		printf("%c\n",num);
	}
};
class c:public b
{
	int num;
public:
	c()
	{
		num='c';
	}
	void print()
	{
		printf("%c\n",num);
	}
};
int main(int argc,char *argv[])
{
	c cc;
	a* pa=&cc;
	pa->print();
	return 0;
}
