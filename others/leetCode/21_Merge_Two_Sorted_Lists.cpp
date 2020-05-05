#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

void read(ListNode * l1);
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	if(l1 == NULL && l2 == NULL) return NULL;
	if(!l1) return l2;
	if(!l2) return l1;
	

	ListNode *ret = l1;
	do {
	if(l1 -> next != NULL) {
		l1 = l1 -> next;
	}	

	}while(l1 -> next);
	l1 -> next = l2; // merge

	for(l1 = ret;l1 -> next; l1 = l1 -> next) {
		for(l2 = ret; l2 -> next; l2 = l2 -> next) {
			if(l2 -> val > l2 -> next -> val) {
				l2 -> val += l2 -> next -> val;
				l2 -> next -> val = l2 -> val - l2 -> next -> val;
				l2 -> val = l2 -> val - l2 -> next -> val;
			}
		}
	}
	return ret;	
    } 
};
void read(ListNode * l1) {

	while(true) {
		cout << l1 -> val << " ";
		if(l1 -> next != NULL) {
			l1 = l1 -> next;
		}else {
			break;
		}
	}	
	cout << endl;

}
int main(void) {

	ListNode a(1), b(2), c(4);
	ListNode d(1), e(3), f(4);

	a.next = &b;	
	b.next = &c;	
	d.next = &e;
	e.next = &f;
	Solution s;
	ListNode *m = s.mergeTwoLists(&a, &d);

	read(m);

	return 0;
}
