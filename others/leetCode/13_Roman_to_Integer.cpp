#include <iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
  	int result = 0;
	int len = s.length();
	int num = 0;
	for(int i = 0; i < len; ) {
		if(s[i] == 'I') {
			if(s[i + 1] == 'V') {
				num = 4;		
				i += 2;
			}else if(s[i + 1] == 'X'){
				num = 9;
				i += 2;
			}else {
				num = 1;
				i += 1;
			}
		}
		else if(s[i] == 'V') {
				num = 5;
				i += 1;
		}
		else if(s[i] == 'X') {
			if(s[i + 1] == 'L') {
				num = 40;		
				i += 2;
			}else if(s[i + 1] == 'C'){
				num = 90;
				i += 2;
			}else {
				num = 10;
				i += 1;
			}
		}
		else if(s[i] == 'L') {
			num = 50;	
			i += 1;
		}
		else if(s[i] == 'C') {
			if(s[i + 1] == 'D') {
				num = 400;		
				i += 2;
			}else if(s[i + 1] == 'M'){
				num = 900;
				i += 2;
			}else {
				num = 100;
				i += 1;
			}
		}
		else if(s[i] == 'D') {
				num = 500;
				i += 1;
		}
		else if(s[i] == 'M') {
				num = 1000;
				i += 1;
		}else {
			num = 0;
			i += 1;
		}	
		result += num;
	}

	return result;      
    }
};
int main(void) {
	Solution s;
	cout << s.romanToInt("LVIII");

	return 0;
}
