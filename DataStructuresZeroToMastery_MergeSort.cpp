#include <iostream>
#include <vector>

using namespace std;

void merge_array(int arr[], int start_a, int end_a, int start_b, int end_b)
{
	//if (end_a <= start_a || end_b <= start_b)
	//	return;

	vector <int> holder;
	int i = start_a;	int j = start_b;

	while (i <= end_a && j <= end_b)
	{
		if (arr[i] > arr[j]) 
		{
			holder.push_back(arr[j]);
			++j;
		}
		
		else {
			holder.push_back(arr[i]);
			++i;
		}
	}

	for (; i <= end_a; ++i)
		holder.push_back(arr[i]);

	for (; j <= end_b; ++j)
		holder.push_back(arr[j]);

	int index = 0;
	for (int k = start_a; k <= end_b; ++k)
		arr[k] = holder[index++];
}

void mergeSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	merge_array(arr, start, mid, mid + 1, end);
}

void mergeSort(int arr[], int size) 
{
	mergeSort(arr, 0, size - 1);
}

int main() {

	const int size = 7;
	int arr[] = { 3,4,14,15,4,10,12 };
	//int arr[] = { 10,9,8,7,6,5,5 };
	
	cout << "Before Merge Sort\n";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << "  ";
	}

	mergeSort(arr, size);

	cout << "\nAfter Merge Sort\n";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << "  ";
	}

	cout << endl;
	return 0;
}