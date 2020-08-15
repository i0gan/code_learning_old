//gcc -nostartfiles -e my_main p2.cc -o t
//nm t #查看符号表

/*
	改变入口函数
*/

%:include <stdio.h>
#include  <stdlib.h>

extern "C" {
int my_main(int , char **) <%
	printf("ok");
	exit(0);
	return 0;
%>
}
