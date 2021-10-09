#include<iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
	int pivot = end;
	int s = start;
	while (start < end)
	{
		while (start < end && arr[start] < arr[pivot])
			++start;

		while (end > s && arr[end] >= arr[pivot])
			--end;

		if (start < end)
		{
			int tmp = arr[start];
			arr[start] = arr[end];
			arr[end] = tmp;
		}
	}
	int new_pivot = start;
	int tmp = arr[pivot];
	arr[pivot] = arr[new_pivot];
	arr[new_pivot] = tmp;

	return new_pivot;
}

void quick_sort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int pivot_index = partition(arr, start, end);

	quick_sort(arr, start, pivot_index-1);
	quick_sort(arr, pivot_index + 1, end);
}

int main()
{
	const int size = 9;
	int arr[size] = {3,4,1,6,3,7,5,5,12};
	
	cout << "Before Sorting: \n";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";

	quick_sort(arr, 0, size - 1);

	cout << "\nAfter Sorting: \n";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";


	cout << endl;
	return 0;
}