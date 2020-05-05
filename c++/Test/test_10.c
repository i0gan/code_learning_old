#include<stdio.h>
#include<string.h>
int main(void){
	char name[16];
	char passwd[16];
	while(1){
	printf("Username:");
	scanf("%s",&name);
	printf("\n");
	printf("Password:");
	scanf("%s",&passwd);
	printf("\n");
	if(!(strcmp(name,"logan"))&&(!(strcmp(passwd,"123456")))){
		printf("You have logged in\n");	
	}
	else printf("Passwrod or account error!\n");
}
		return 0;
}
