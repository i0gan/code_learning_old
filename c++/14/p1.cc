// g++ p1.cc --std=c++14


/*
	Table 1 --Trigraph sequences
	??=   #
	??/   \
	??'   ^
	??(   [
	??)   ]
	??!   |
	??<   {
	??>   }
	??-   ~
*/

/*
	
	and   &&
	bitor |
	or    ||
	xor   ^
	compl ~
	bitand &
	and_eq &=
	or_eq  |=
	xor_eq ^=
	not    !
	not_eq !=
*/	

/*
    <%   {
    %>   }
    <:   [
    :>   ]
    %:   #
    %:%: ##
*/

%:include <iostream>
??=include <string>
thread_local int g_a;
volatile const char *name = "I0gan";

??=define OK 0
void array() {
	char a [3] = {1, 2, 3};
	char b <:3:> = {1, 2, 3};
	char c <:3:> = <%1, 2, 3%>;
	char d ??(3??) = ??<1, 2, 3??>;
}
static inline void operator_() <%
	if(not(true and false)) <%
		::std::cout << false << ::std::endl;	
	%>
	else <%
		::std::cout << true << ::std::endl;	
	%>
%>
static inline int plus_(int a, int b) ??<
	asm("add %1, %0": "+r"(a):"r"(b));
	return a;
}

int main(int, char**) ??<
	operator_();
	::std::cout << "result: " << plus_(1, 2) << ::std::endl;
	::std::cout << "name  : " << ::name << ::std::endl;
	//::std::terminate();
??>
