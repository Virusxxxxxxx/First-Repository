#include <string>
#include <iostream>
using namespace std;
string getHint(string secret, string guess) {
	int A = 0, B = 0;
	string res;
	int length = secret.length();
	int s[10] = { 0 };
	int g[10] = { 0 };
	int a1 = stoi(secret);
	int a2 = stoi(guess);
	int secret1[99];
	int guess1[99];
	for (int i = 0; i < length; i++)
	{
		int p = pow(10, length - 1 - i);
		secret1[i] = (a1 / p) % 10;
		guess1[i] = (a2 / p) % 10;
	}
	for (int i = 0; i < length; i++)
	{
		if (secret[i] == guess[i])
			A++;
		s[secret1[i]]++;
		g[guess1[i]]++;
		//cout << "g[guess[i]] : "<<g[guess[i]] << '\t'<<"i = " << i <<endl;
	}
	for (int i = 0; i < 10; i++)
	{
		if (s[i] == 0)
			continue;
		if (g[i] > 0)
		{
			B++;
			if (g[i] > s[i])
				B++;
		}
	}
	B = B - A;
	//cout << A << B;
	res =  to_string(A) + "A" + to_string(B) + "B";
	return res;
}
int main()
{
	string secret, guess;
	cin >> secret >> guess;
	int A = 0, B = 0;
	cout << getHint(secret, guess) <<endl;
	system("pause");
}