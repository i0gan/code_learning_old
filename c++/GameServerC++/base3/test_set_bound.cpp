#include <set>
#include <iostream>

void test_set_bound() {

	std::set<int> a {1, 4, 2, 5, 6};
	for(const auto &v : a) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	std::cout << "check to insert 3 for position:" << std::endl;
	auto lb = a.lower_bound(3);
	auto ub = a.upper_bound(3);
	auto er = a.equal_range(3);

	std::cout << "lower bound for 3 " << *lb << std::endl;
	std::cout << "upper bound for 3 " << *ub << std::endl;
	std::cout << "equal range for 3 " << *(er.first) << " : "
		<< *(er.second) << std::endl;

	std::cout << "check to insert 5 for position" << std::endl;
	lb = a.lower_bound(5);
	ub = a.upper_bound(5);
	er = a.equal_range(5);

	
	std::cout << "lower bound for 5 " << *lb << std::endl;
	std::cout << "upper bound for 5 " << *ub << std::endl;
	std::cout << "equal range for 5 " << *(er.first) << " : "
		<< *(er.second) << std::endl;
}

int main(void) {
	test_set_bound();
}
