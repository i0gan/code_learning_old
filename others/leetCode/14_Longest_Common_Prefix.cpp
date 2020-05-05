#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	string result("");
	vector<int> str_len_arr;
	int i = 0;
	int str_n = strs.size();
	if (str_n == 0) return result;

	for(i = 0; i < str_n; i++) {
		str_len_arr.push_back(strs[i].length());
	}

	for(i = 0; i < str_n - 1; i++) {
		if(str_len_arr[i] > str_len_arr[i + 1]) {
			str_len_arr[i] += str_len_arr[i + 1];
			str_len_arr[i + 1] = str_len_arr[i] - str_len_arr[i + 1];
			str_len_arr[i] = str_len_arr[i] - str_len_arr[i + 1];
		}
	}
	int min = str_len_arr[0];
	i = 0;
	while(true) {
		for(int j = 1; j < str_n; j++) {
			if(strs[j][i] != strs[0][i]) {
				goto NO;
			}
		}
//		cout << "debug" << i << endl;
		result += strs[0][i];
		i++;
		if(i >= min) break;
	}
	NO:	
	return result;
    }
};
int main(void) {
	Solution s;
	vector<string> strs(2);
	strs[0] = "A";
	strs[1] = "AA";
	
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}
