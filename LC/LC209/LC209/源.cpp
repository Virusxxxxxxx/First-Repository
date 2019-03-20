#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int sum = 0;
			int k = 0;
			if (i == 0) {
				for (int j = 0; j < nums.size(); j++) {
					sum += nums[i];
					res++;
					if (sum >= s) break;
				}
				continue;
			}
			for (int j = i; j <= i + res - 1 && j < nums.size(); j++)
			{
				sum += nums[j];
				if (sum >= s) {
					res = j - i + 1;
					break;
				}
			}
		}
		return res;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		int s = stringToInteger(line);
		getline(cin, line);
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().minSubArrayLen(s, nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}