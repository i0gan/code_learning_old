#include <iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
	int j = 0;
	char ch = 0;

	for(int i = 0; i < len; ) {
		switch(s[i]) {
		case '{': {
			if(i + 1 >= len){
				return false;
			}
			for(j = i + 1; j < len; ) {
				if(s[j] == ' ' ){
					j++;
				} else if (s[j] == '}') {
					s[i] = ' ';
					s[j] = ' ';
					while(i > 0) {
						if(s[i] == '{' || s[i] == '[' || s[i] == '(') break;
						else i --;
					}
					break;
				}else {
					i ++;
					break;
				}
				if(j >= len) return false;
			}
		} break;
		case '[': {
			if(i + 1 >= len){
				return false;
			}
			for(j = i + 1; j < len; ) {
				if(s[j] == ' ' ){
					j++;
				} else if (s[j] == ']') {
					s[i] = ' ';
					s[j] = ' ';
					while(i > 0) {
						if(s[i] == '{' || s[i] == '[' || s[i] == '(') break;
						else i --;
					}
					break;
				}else {
					i ++;
					break;
				}
				if(j >= len) return false;
			}
		} break;
		case '(': {
			if(i + 1 >= len){
				return false;
			}
			for(j = i + 1; j < len; ) {
				if(s[j] == ' ' ){
					j++;
				} else if (s[j] == ')') {
					s[i] = ' ';
					s[j] = ' ';
					while(i > 0) {
						if(s[i] == '{' || s[i] == '[' || s[i] == '(') break;
						else i --;
					}
					break;
				}else {
					i ++;
					break;
				}
				if(j >= len) return false;
			}
		} break;

		default : {
			i++;
		}
		}
	}

	for(int k = 0; k < len; k++) {
		if(s[k] != ' ') return false;
	}
	return true;	
    }

};
int main(void) {
	Solution s;
	cout << endl <<  s.isValid("[][]");
	return 0;
}
