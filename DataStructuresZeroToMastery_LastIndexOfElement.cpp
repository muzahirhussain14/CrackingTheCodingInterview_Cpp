#include <iostream>
using namespace std;


int last_index_of_element(int* arr, int n, const int element)
{
	if (n < 0)
		return -1;

	if (arr[n] == element)
		return n;

	return last_index_of_element(arr, n-1, element);
}

int main()
{
	int arr[5] = { 3,2,1,1,4 };
	cout << "Last Index of: " << last_index_of_element(arr, 5, 10) << "\n";


	cout << endl;
	return 0;
}