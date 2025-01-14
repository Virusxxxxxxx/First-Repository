#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int now = 0;
		for (int i = 0; i != nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				continue;
			}
			else
			{
				nums[now] = nums[i];
				now++;
			}
		}
		for (int i = now; i != nums.size(); i++)
			nums[i] = 0;

		/*	����swap����
		for(int cur = 0, lastNonZeropos = 0; cur < nums.size(); ++cur) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeropos++], nums[cur]);
            }
        }
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

		Solution().moveZeroes(nums);

		string out = integerVectorToString(nums);
		cout << out << endl;
	}
	return 0;
}