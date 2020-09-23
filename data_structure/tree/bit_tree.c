#include <stdlib.h>
#include <stdio.h>

typedef int tree_ele;

typedef struct tree{
	tree_ele ele;
	struct tree *left_child;
	struct tree *right_child;
} *ptree;

int is_number(int n) {
	
}
ptree create_tree() {
	tree_ele ele;
	int ret = scanf("%d", &ele);
	if(ret == 0) return NULL;

	ptree head = (ptree) malloc(sizeof(tree_ele));
	head->ele = ele;
	head->left_child = create_tree();
	head->right_child = create_tree();
	return head;
}

void print_pre(ptree t) {
	if(t == NULL) return;
	printf("%d", t->ele);
	print_pre(t->left_child);
	print_pre(t->right_child);
}

void print_mid(ptree t) {
	if(t == NULL) return;
	print_pre(t->left_child);
	printf("%d", t->ele);
	print_pre(t->right_child);
}

void print_post(ptree t) {
	if(t == NULL) return;
	print_pre(t->left_child);
	print_pre(t->right_child);
	printf("%d", t->ele);
}

int main(void) {
	ptree t = create_tree();
	puts("\n----pre order-----\n");	
	print_pre(t);
	puts("\n----mid order-----\n");	
	print_mid(t);
	puts("\n----post order-----\n");	
	print_post(t);
	puts("\n");
	return 0;
}
