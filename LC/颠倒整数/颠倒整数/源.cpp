#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int num[100];
		int i = 0;
		int count = 0;
		bool isAbsolute = 0;
		if (x < 0)
		{
			x = -x;
			isAbsolute = 1;
		}
		while (x != 0)
		{
			num[i] = x % 10;
			x /= 10;
			i++;
			count++;
		}
		int sum = 0;
		for (int i = count-1,j = 0; i >= 0; i--)
		{
			int temp = sum;
			sum += (num[j] * pow(10, i));
			j++;
			if (temp > sum || sum < 0)
				return 0;
		}
		if (isAbsolute == 0)
			return sum;
		else
			return (-sum);
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		int ret = Solution().reverse(x);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}