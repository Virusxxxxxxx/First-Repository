#include <iostream>
#include<string>
#include <sstream>
#include <assert.h>
using namespace std;
static const int _ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;

}();
class Solution {
public:
	bool isAnagram(string s, string t) {
		int slen = s.size();
		int tlen = t.size();
		if (slen != tlen) return false;
		if (s == "" && t == "") return true;
		int srecord[26] = { 0 };
		int trecord[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			srecord[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++)
		{
			trecord[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (srecord[i] != trecord[i])
				return false;
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
		getline(cin, line);
		string t = stringToString(line);

		bool ret = Solution().isAnagram(s, t);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}