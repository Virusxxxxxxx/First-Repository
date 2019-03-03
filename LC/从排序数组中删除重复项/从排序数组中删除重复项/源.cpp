#include <iostream>
using namespace std;
void swap(int arr[], int lhs, int rhs)
{
	int temp = arr[lhs];
	arr[lhs] = arr[rhs];
	arr[rhs] = temp;
}
void print(int arr[], int last)
{
	for (int i = 0; i <= last; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int removeDuplicates(int arr[], int nSize, int last)
{

	for (int i = 1; i <= last; i++)
	{
		int temp = i;
		bool swapped = 0;
		while (temp >= 1)
		{
			if (arr[i] == arr[temp - 1])
			{
				swap(arr[i], arr[last]);
				last--;
				swapped = 1;
				if (last < i)
					break;
			}
			temp--;
			if (swapped == 1)
			{
				temp = i;
				swapped = 0;
			}
		}
	}
	print(arr, last);
	return (last+1);

}
int main()
{
	//int arr[20] = { 1,1,3,3,3,4,4,6,6,6,7,7,7,7,7,8,8,8,8,8};
	int arr[3];
	for (int i = 0; i != 3; i++)
	{
		cin >> arr[i];
	}
	int Size = sizeof(arr) / sizeof(*arr);
	int last = Size - 1;
	cout << removeDuplicates(arr, Size, last) << endl;
	system("pause");
	return 0;
}
