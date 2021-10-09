#include<iostream>
using namespace std;

int binary_search_rotatedSortedArray(const int arr[], int start, int end, const int key, const int SIZE)
{
	if (start < 0 || end < 0)
		return -1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (key == arr[mid])
			return mid;

		if (key <= arr[SIZE - 1])
		{
			if (key <= arr[end])
				start = mid + 1;

			else if (key >= arr[start])
				end = mid - 1;
		}
		else
		{
			if (key > arr[mid])
				start = start + 1;

			else if (key < arr[mid])
				end = mid - 1;
		}
	}

	return -1;
}

int main()
{
	const int SIZE = 9;
	int arr[SIZE] = { 5,6,7,8,9,1,2,3,4 };

	cout << "Binary Search: " << binary_search_rotatedSortedArray(arr, 0, SIZE - 1, 5, SIZE);


	cout << endl;
	return 0;
}