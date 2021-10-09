/*
	Majority Element: Element that is appearing more than n/2 times where n is the size of the array. We can assume majority element always exists.
*/

#include <iostream>
using namespace std;

int majority_element(int arr[], const int SIZE)
{
	int majority_element = arr[0];
	int majority_element_count = 1;

	for (int i = 1; i < SIZE; ++i)
	{
		if (arr[i] == majority_element)
			++majority_element_count;

		else
		{
			--majority_element_count;

			if (majority_element_count == 0)
			{
				majority_element = arr[i];					// make current element the new majority element
				majority_element_count = 1;
			}
		}
	}

	return majority_element;
}

int main()
{
	const int SIZE = 10;
	int arr[SIZE] = { 4,7,4,4,7,7,7,7,4,7 };
	cout << "Majority Element: " << majority_element(arr, SIZE);


	cout << endl;
	return 0;
}