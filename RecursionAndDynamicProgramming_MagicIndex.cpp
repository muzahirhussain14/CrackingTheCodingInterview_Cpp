#include<iostream>
using namespace std;

int magic_index(int arr[], int size, int start, int end)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;

	if (arr[mid] == mid)
		return mid;

	else if (arr[mid] < mid)
		return magic_index(arr, size, mid + 1, end);

	else
		return magic_index(arr, size, start, mid - 1);
}

int magic_index(int arr[], int size)
{
	return magic_index(arr, size, 0, size - 1);
}

int main()
{
	int arr[6] = { -4,0,1,2,4,5 };
	cout << "Magic Index: " << magic_index(arr, 6);


	cout << endl;
	return 0;
}