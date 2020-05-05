#include <iostream>
#include <vector>
#include <algorithm>

//objects储存了很多的数值,排序后,只需要前10个,发现内存里的值没有真正删除
void isGoodOrBad(std::vector<int>& objects) {
	//objects is very huge
	//we only need top ten
	std::sort(objects.begin(), objects.end());
	if(objects.size() > 10) {
		objects.erase(objects.begin() + 10, objects.end());	
	}
}

int main(void) {
	return 0;
}
