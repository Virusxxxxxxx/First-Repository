#include <stdio.h>
#include<iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include<iterator>
#include<stdio.h>
#include <string>
using namespace std;
void select_sort(char *table[], int size)
{
	for (int i = 1; i < size; i++)
	{
		char *p = table[i];
		int j = i - 1;
		for (j; j >= 0; j--)
		{
			if (strcmp(p, table[j]) < 0)
				table[j + 1] = table[j];
			else
				break;
		}
		table[j + 1] = p;
	}
}
struct NODE
{
	int data;
	NODE *next;
};
void reverse_node(NODE*& L, int table[], int n)
{
	L = NULL;
	if (n < 0)return;
	int i = 0;
	NODE *p;
	while (i < n)
	{
		p = new NODE;
		p->data = table[i];
		p->next = L;
		L = p;
		i++;
	}
}
void p_swap(int *a, int *b)
{
	int z = *a;
	*a = *b;
	*b = z;
}
void greatest_common_divisor(int num1, int num2)
{
	//�ж�num1 num2�Ƿ���Ч
	do
	{
		cin >> num1 >> num2;
	} while (num1 < 3 && num2 < 3);		//num1 num2С��3û������

	//շת����������Լ��
	int t;
	while (num1 != 0 && num2 != 0)
	{
		t = num1 % num2;
		num1 = num2;
		num2 = t;
	}
	cout << "���Լ����" << num1 << endl;
}
void recursive(int n)	//�ݹ�
{
	if (n != 0)
	{
		recursive(n - 1);
		for (int i = 0; i < n; i++) cout << n;
		cout << endl;
	}
}

class A {
private:
	friend class B;
	A(int val = 0):data(val),use(1){}
	int use, data;
};
class B {
public:
	A *pa;
	B(int val = 0):pa(new A(val)){}
	~B() {
		if (--pa->use == 0) delete pa;
	}
	B(B &rhs) {
		++rhs->use; 
		pa = rhs.pa;
	}
	B &operator=(B &rhs);
	A *operator->() { return pa; }
	void Display()
	{
		cout << "data = " << pa->data << ", use = " << pa->use << endl;
	}
};
B &B::operator=(B &rhs)
{
	if (this == &rhs) return *this;
	if (--pa->use == 0)
		delete pa;
	++rhs->use;
	pa = rhs.pa;
	return *this;
}
void main()
{
	B b1(1);
	B b2(b1);
	B b3(3);
	b1.Display();
	b2.Display();
	b3.Display();
	b3 = b1;
	b1.Display();
	b3.Display();
	system("pause");
}