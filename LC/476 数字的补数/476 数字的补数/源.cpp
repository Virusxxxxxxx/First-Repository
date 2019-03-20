#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <unordered_map>
#include<functional>
#include <math.h>
using namespace std;
class Solution {
public:
	int findComplement(int num) {
		string str;
		int res = 0;
		while (num)
		{
			int i = num % 2;
			num /= 2;
			str += to_string(i);
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '0')
				res += pow(2, i);
		}
		return res;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int num = stringToInteger(line);

		int ret = Solution().findComplement(num);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}