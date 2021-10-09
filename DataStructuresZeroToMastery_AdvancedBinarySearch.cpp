#include<iostream>
#include<vector>
using namespace std;

vector<int> binary_search(int arr[], int start, int end, const int number)
{

	if (start > end)
	{
		vector<int> result;
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}

	int mid = (start + end) / 2;

	if (number < arr[mid])
	{
		return binary_search(arr, start, mid - 1, number);
	}
	else if (number > arr[mid])
	{
		return binary_search(arr, mid + 1, end, number);
	}
	else			// mid is the index of the first occurance found
	{
		vector<int> start_index = binary_search(arr, start, mid - 1, number);
		vector<int> end_index = binary_search(arr, mid + 1, end, number);
		vector<int> result;

		if (start_index.back() == -1 && end_index.back() == -1)				// if no other occurance is found, this return this occurance
		{
			result.push_back(mid);
			result.push_back(mid);
		}
		else if (start_index.back() == -1)									// if only one occurance is found on left side
		{
			result.push_back(mid);
			result.push_back(end_index.back());
		}
		else if (end_index.back() == -1)													// if occurance is found on right
		{
			result.push_back(start_index.front());
			result.push_back(mid);
		}
		else
		{
			result.push_back(start_index.front());
			result.push_back(end_index.back());
		}

		return result;
	}
}


int main()
{
	const int SIZE = 11;
	int arr[SIZE] = { 2,2,4,5,5,5,5,5,7,7,9 };
	vector<int> output = binary_search(arr, 0, SIZE - 1, 5);

	// print the result
	for (int i : output)
	{
		cout << i << "\n";
	}
	cout << endl;
	return 0;
}