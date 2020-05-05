#include <iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int _x = 0;
		bool if_minus = false;
		if(x == 0x80000000) return 0;

		if(x == 0) return 0;

		if(x < 0) {
			if_minus = true;
			_x = (0 - x);
		}else _x = x;

		int times = 0;	
		unsigned int num = _x;	
		long long result = 0;
		unsigned long long uresult = 0;

		do {
		times = num % 10;
		result *= 10;
		result += times;

		}while(num /= 10);
		uresult = (unsigned long long)result;

		if(uresult > 0xFFFFFFFF) {
			return 0;
		}else if(0 - result > 0xFFFFFFFF) {
			return 0;
		}


		if(if_minus) {
			if(if_minus == ((int)(0 - result) > 0)) return 0;
		 	else return (int)(0 - result);
		}else {
			if(if_minus == ((int)(result) > 0)) return 0;
		 	else return (int)result;
		}
	}
	
};
int main(void) {
	Solution s;
	cout <<  s.reverse(123);
//	cout <<  s.reverse(1563847412);

	return 0;
}
