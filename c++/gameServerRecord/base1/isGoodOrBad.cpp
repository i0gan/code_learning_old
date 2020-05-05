#include <iostream>
#include <vector>
using namespace std;

void isGoodOrBad(const std::vector<int> &objects) {
	vector<int> tar;
	int pos = 0;
	/*
	if(tar.size() <= tar.capacity()) {
		tar.push_back():	
	}*/
	if(pos == objects.size() - 1) {
		tar.push_back(objects[pos]);	
		for(int i = 0; i < pos; i++) { //采用for循环来push_back则会效率比较底
			tar.push_back(objects[i]); //且每一个push_back时,就会开辟一个内存空间
		}
	}
}
void isGoodOrBad_2(const std::vector<int> &objects) {
	std::vector<int> tar;
	int pos = 0;
	if(pos == objects.size() - 1) {
		tar.push_back(objects[pos]);
		tar.insert(tar.end(), objects.begin(), objects.begin() + pos); //采用insert则会效率更高
	}
}
int main(void) {
	return 0;
}
