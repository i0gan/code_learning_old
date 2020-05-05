#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
	int num_arr[16] = {0};	
	int len = 0;
	int num = x;
	if(x < 0) return false;

	do {
		num_arr[len] = num % 10;
		++ len;
	}while(num /= 10);
	

	for(int j = 0; j < len; j++){
		if(num_arr[j] != num_arr[len - j -1])
			return false;
	}	
	return true;
    }
};

int main(void) {
	Solution s;
	cout << s.isPalindrome(11);
	return 0;
}
