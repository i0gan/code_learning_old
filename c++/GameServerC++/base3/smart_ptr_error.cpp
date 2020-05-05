#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>
//#include <celero/Celero.h>
//智能指针的效率问题


using ptr = std::shared_ptr<int>;
using weakPtr = std::weak_ptr<int>;

static std::vector<int> origin; //时间消耗: 1
static std::vector<ptr> group;	//时间消耗: 1.5
static std::vector<weakPtr> group2; //时间消耗: 14
static std::vector<int*> group3; //时间消耗: 1.2
static std::vector<double> bigValues;


///
// This is the main(int argc, char** argv) for the entire celero program
// You can write your own, or use this macro to insert the standard one into the project.
///
void test_1() {
	for(int i = 0; i < 100000; ++i) {
		origin.push_back(i);	
		auto p = std::make_shared<int>(i);
		group3.push_back(p.get());
		group2.push_back(p);
		group.push_back(p);
	}
	std::cout << group.size() << " " << group2.size() << " " << group3.size() << std::endl;
}

int main(int, char**) {
	test_1();
	return 0;
}
