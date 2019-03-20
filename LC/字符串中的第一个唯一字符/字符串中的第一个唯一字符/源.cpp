#include <string>
#include <sstream>
#include <iostream>
#include <assert.h>
#include<vector>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		/*
		if (s == "") return -1;
		string temp = s;
		for (int i = 0; i < temp.size(); i++)
		{
			bool isSame = 0;
			for (int j = i + 1; j < temp.size(); j++)
			{
				if (temp[i] == temp[j])
				{
					temp.erase(j, 1);
					j--;
					isSame = 1;
				}
			}
			if (isSame == 0)
			{
				for (int r = i; r < s.size(); r++)
				{
					if(temp[i] == s[r])
						return r;
				}
			}
			if (i == temp.size()-1)
				return -1;
		}
	*/
		static auto x = []()
		{
			ios::sync_with_stdio(false);
			cin.tie(nullptr);
			return 0;
		}();
		int len = s.size();
		if (len == 0)
			return -1;
		if (len == 1)
			return 0;
		int record[26] = { 0 };
		for (int i = 0; i<len; i++)
			record[s[i] - 'a']++;
		for (int i = 0; i<len; i++)
			if (record[s[i] - 'a'] == 1)
				return i;
		return -1;

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

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		int ret = Solution().firstUniqChar(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}