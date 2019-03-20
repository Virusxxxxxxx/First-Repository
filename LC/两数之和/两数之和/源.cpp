#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> temp = nums;
		sort(temp.begin(), temp.end());
		vector<int> result;
		bool isFound = 0;
		int num1, num2;
		for (int i = 0; i != nums.size(); i++)
		{
			for (int j = i + 1; j != temp.size(); j++)
			{
				int sum = 0;
				sum = temp[i] + temp[j];
				if (sum == target)
				{
					num1 = temp[i];
					num2 = temp[j];
					isFound = 1;
					break;
				}
				else if (sum > target)
					break;
			}
			if (isFound == 1) break;
		}
		for (int i = 0; i != nums.size(); i++)
		{
			int ready1, ready2;
			if (nums[i] == num1)
			{
				result.push_back(i);
				ready1 = i;
			}
			if (nums[i] == num2 && i!= ready1)
				result.push_back(i);
		}
		return result;
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

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);

		vector<int> ret = Solution().twoSum(nums, target);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}