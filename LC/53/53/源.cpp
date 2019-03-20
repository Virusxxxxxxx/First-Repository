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
	int maxSubArray(vector<int>& nums) {
		int max, res;
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		max = nums[0];
		res = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int temp = max + nums[i];
			if (max > res)
					res = max;
			if (temp >= 0)
			{
				max += nums[i];
				if (max > res)
					res = max;
			}
			else
			{
				if (max > res)
					res = max;
				if (nums[i] < 0 && i + 1 < nums.size())
					max = nums[++i];
				else
					max = nums[i];
			}
		}
		return max > res ? max : res;
	}
};

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
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().maxSubArray(nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}