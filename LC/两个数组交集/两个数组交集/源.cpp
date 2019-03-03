#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> same;
		if (nums1.size() == 0 || nums2.size() == 0)
			return same;
		int temp = 0;

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int max = nums1[0];
		int pushed = 0;
		for (int i = 0; i < nums1.size(); i++)
		{
			if (pushed == 1) i--;
			if (max == nums1[i] && i != 0)
			{
				pushed = 0;
				continue;
			}
			pushed = 0;
			for (int j = temp; j < nums2.size(); j++)
			{
				while (nums1[i] == nums2[j])
				{
					same.push_back(nums1[i]);
					max = nums1[i];
					++i; ++j;
					pushed = 1;
					if (j == nums2.size())
						break;
				}
				if (j == nums2.size())
					break;
				temp = j;
				if(nums1[i]<nums2[j])
					break;
				
			}
		}
		return same;
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
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);

		vector<int> ret = Solution().intersect(nums1, nums2);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}