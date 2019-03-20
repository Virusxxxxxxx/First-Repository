#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	int num;
	int Case[3];
	int i = 0;
	int k = 0;
	ofstream c("Case.txt");
	while (1)
	{
		bool isFound = 0;
		for (i = 0; i < 3; i++)
		{
			cin >> Case[i];
		}
		if (Case[0] == -1)
			break;
		if (k) c << endl;
		for (int j = 10; j <= 100; j++)
		{
			if (Case[0] >= 3 || Case[1] >= 5 || Case[2] >= 7)
			{
				c << "#Wrong data#";
				break;
			}
			if (j % 3 == Case[0] && j % 5 == Case[1] && j % 7 == Case[2])
			{
				c << "Case " << ++k << ": " << j << endl;
				isFound = 1;
			}
		}
		if (isFound == 0)
			c << "No answer" << endl;
	}
	std::system("pause");
}