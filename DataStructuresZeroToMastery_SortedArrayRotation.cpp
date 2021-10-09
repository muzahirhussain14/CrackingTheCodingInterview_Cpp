#include <iostream>
using namespace std;

void array_rotation(int arr[], const int SIZE, int pivot_index)
{
	if (pivot_index <= 0 || pivot_index >= SIZE)
		return;

	else
	{
		int start = 0;
		int end = pivot_index;

		while (end < SIZE)
		{
			int current = arr[start];
			for (int i = start + 1; i <= end; ++i)
			{
				int temp = arr[i];
				arr[i] = current;
				current = temp;
			}
			arr[start] = current;

			++end;
			++start;
		}
	}
}
int main()
{
	const int SIZE = 5;
	int arr[SIZE] = { 1,2,3,4,5 };
	
	
	cout << "\nBefore Rotation\n";
	for (int i = 0; i < SIZE; ++i)
		cout << arr[i] << " ";


	array_rotation(arr, SIZE, 4);

	cout << "\nAfter Rotation\n";
	for (int i = 0; i < SIZE; ++i)
		cout << arr[i] << " ";

	cout << endl;
	return 0;
}