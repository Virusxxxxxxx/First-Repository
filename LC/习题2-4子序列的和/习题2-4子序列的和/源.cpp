#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int lhs = 1, rhs = 1;
	while (1)
	{
		double sum = 0;
		cin >> lhs >> rhs;
		if (lhs == 0 && rhs == 0)
			break;
		for (int i = lhs; i <= rhs; i++)
		{
			sum += 1 / ((double)i*(double)i);
		}
		cout << fixed << setprecision(5) << sum << endl;
	}
	system("pause");
}