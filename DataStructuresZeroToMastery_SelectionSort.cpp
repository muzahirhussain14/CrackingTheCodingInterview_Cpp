/*
	SelectionSort, sorts the array by repeatedly finding the minimum element from unsorted part and putting it at the beginning. 
*/

#include <iostream>
using namespace std;

int find_min_index(int arr[], int start_index, int end_index)
{
	int min = arr[start_index];
	int index = start_index;

	for (int i = start_index+1; i <= end_index; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
	}

	return index;
}

void selection_sort(int arr[], int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		int min_index = find_min_index(arr, i + 1, size - 1);

		if (arr[i] > arr[min_index])
		{
			// swap
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}

int main()
{
	const int SIZE = 8;
	//int arr[SIZE] = { 3,2,5,6,2,1,7,6 };
	int arr[SIZE] = { 8,7,6,5,4,3,2,1 };

	cout << "Before Sorting\n";
	for (int i : arr)
	{
		cout << i << "  ";
	}

	selection_sort(arr, SIZE);

	cout << "\nAfter Sorting\n";
	for (int i : arr)
	{
		cout << i << "  ";
	}

	cout << endl;
	return 0;
}