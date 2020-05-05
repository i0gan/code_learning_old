#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
void changeOrder(char *data) {
	string str = data;
	stack<char> tmp;
	for(char i:str) {
		tmp.push(i);
	}
	int i =  0;
	while(tmp.size() > 0) {
		data[i] = tmp.top();
		tmp.pop();
		i++;
	}
}
void changeOrder2(char *data) {
	auto l = strlen(data);
	std::reverse(data, data + l);
}
void changeOrder3(char *data) {
	auto l = strlen(data);
	if(l <= 1) return ;
	auto m = l / 2;
	auto start = 0;
	while(start < m) {
		std::swap(data[start], data[l - start - 1]);
		++start;
	}
}
int main(void) {
	char t[] = "123456";
	cout << "orignal: " << t << endl;
	changeOrder(t);
	cout << t << endl;
	changeOrder2(t);
	cout << t << endl;
	changeOrder3(t);
	cout << t << endl;
	return 0;
}
