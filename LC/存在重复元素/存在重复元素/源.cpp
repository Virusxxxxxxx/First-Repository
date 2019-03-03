#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include <iterator>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		vector<int>::iterator bg, ed;
		bg = nums.begin();
		ed = nums.end();
		sort(bg, ed);
		vector<int>::iterator a = nums.begin();
		a++;
		for (a; a != nums.end(); ++a)
		{
			if (*a == *(a - 1))
			{
				return true;
			}
		}
		return false;
		
		
		
		
		
		
		
		
		/*
		if (nums.size() == 0) return false;
		for (int i = 0; i != nums.size(); i++)
		{
			for (int j = i + 1; j != nums.size(); j++)
			{
				if (nums[i] == nums[j])
				{
					return true;
				}
			}
		}
		return false;
		*/
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		bool ret = Solution().containsDuplicate(nums);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}