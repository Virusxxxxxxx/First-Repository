#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <assert.h>
using namespace std;
class Solution {
public:
	bool validPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		int l1 = 0;
		int r1 = 0;
		bool flag = false;
		bool in_flag = false;
		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++; right--;
			}
			else
			{
				if (s[left] == s[right - 1] && s[left + 1] == s[right] && !in_flag)
				{
					l1 = left;
					r1 = right;
					in_flag = true;
				}
				if (!flag)
				{
					if (s[left] == s[right - 1])
					{
						flag = true;
						left++;
						right -= 2;
						continue;
					}
					if (s[left + 1] == s[right])
					{
						flag = true;
						left += 2;
						right--;
						continue;
					}
				}
				if (in_flag && l1 != -1)
				{
					left = l1 + 1;
					right = r1;
					l1 = -1;
					continue;
				}
				return false;
			}

		}
		return true;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		bool ret = Solution().validPalindrome(s);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}