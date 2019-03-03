#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <unordered_map>
#include<functional>
using namespace std;
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> hashmap;
		for (int i = 0; i < s.size(); i++)
			hashmap[s[i]]++;
		vector<pair<int, char>> temp;
		for (auto it = hashmap.begin(); it != hashmap.end(); it++)
			temp.push_back(make_pair(it->second, it->first));
		sort(temp.begin(), temp.end(), greater<pair<int, int>>());
		string res;
		res.resize(s.size());
		int index = 0;
		auto it = temp.begin();
		while (it != temp.end())
		{
			for (int i = 0; i < it->first; i++)
			{
				res[index] = it->second;
				index++;
			}
			it++;
		}
		return res;
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

		string ret = Solution().frequencySort(s);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}