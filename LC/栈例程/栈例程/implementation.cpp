#include "statement.cpp";
#include <iostream>
using namespace std;
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}
Stack CreateStack(int MaxElement)
{
	Stack S;
	if (MaxElement < MinStackSize)
		cout << "Error( 'Stack size is too small' )";
	S = new StackRecord;
	if (S == NULL)
		cout << "FatalError('Out of space!')";
	S->Array = new ElementType[MaxElement];
	if (S->Array == NULL)
	{
		cout << "FatalError('out of space!')";
	}
	S->Capacity = MaxElement;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		delete[] S->Array;
		delete S;
	}
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(int X, Stack S)
{
	if (IsFull(S))
	{
		cout << "Full stack";
	}
	else
		S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	cout << "Empty stack";
	return 0;
}

void Pop(Stack S)
{
	if (IsEmpty(S))
		cout << "Empty stack";
	else
		S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	cout << "Empty stack";
	return 0;
}
