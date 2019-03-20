#include <iostream>
using namespace std;
int main()
{
	for (int i = 100; i < 1000; i++)
	{
		int n1 = i / 100;
		int n2 = (i / 10) % 10;
		int n3 = i % 10;
		if (n1*n1*n1 + n2*n2*n2 + n3*n3*n3 == i)
			cout << i << endl;
	}
	system("pause");
}