#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef struct _tag_SeqList {
	unsigned int length;
	unsigned int capacity;
	unsigned int *node;

}SeqList;

SeqList* SeqList_Create(int capacity);
int SeqList_Destroy(SeqList *list);

int main(void){

	return 0;
}

SeqList* SeqList_Create(int capacity) {
	SeqList *tmp = NULL;
	tmp = (SeqList*) malloc(sizeof(SeqList));
	if(tmp == NULL) {
		cout << "func SeqList_Creat() err: ";
		exit(-1);
	}
	tmp->node = (unsigned int *)malloc(sizeof(unsigned int*) * capacity);
	if(tmp->node == NULL) {
		cout << "func SeqList_Create() err: malloc err";
		exit(-2);
	}
	memset(tmp, 0, sizeof(SeqList));
	tmp -> length = 0;

	return tmp;
}

int SeqList_Destroy(SeqList *list) {
	SeqList *tlist = NULL;
	if(list == NULL) {
	return -1;
	}
	tlist = (SeqList *)list;
	if(tlist->node != NULL) {
		free(tlist->node);
	}
	free(tlist);
}
