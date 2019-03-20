#include <stdio.h>
#include<iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include<iterator>
#include<stdio.h>
#include <string>
using namespace std;
class base
{
public:
	virtual void f1()
	{
		cout << "fl function of base"<< endl;
	}
	virtual void f2()
	{
		cout << "f2 function of base" << endl;
	}
	virtual void f3()
	{
		cout << "f3 function of base" << endl;
	}
	void f4() { cout << "f4 function of base" << endl; }
};
class derive :public base
{
	void f1()
	{
		cout << "f1 function of derive" << endl;
	}
	void f2(int x)
	{
		cout << "f2 function of derive" << endl;
	}
	void f4()
	{
		cout << "f4 function of derive" << endl;
	}
};
void main()
{
	base obj1,*P;
	derive obj2;
	P = &obj1; 
	P->f1();
	P->f2();
	P->f3();
	P = &obj2;
	P->f1();
	P->f2();
	P->f4();
	system("pause");
}