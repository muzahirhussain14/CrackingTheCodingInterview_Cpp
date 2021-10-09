#include <iostream>
#include <vector>
using namespace std;

vector<int> store_all_positions_of_elements(int* arr, int n, const int element, const int size)
{
	vector<int> result;

	if (n == size)
		return result;

	if (arr[n] == element)
		result.push_back(n);

	vector<int> returned_vec = store_all_positions_of_elements(arr, n + 1, element, size);
	result.insert(result.end(), returned_vec.begin(), returned_vec.end());

	return result;
}

int main()
{
	int arr[8] = { 3,2,1,1,4,2,7,1 };
	vector<int> result = store_all_positions_of_elements(arr, 0, 1, 8);

	cout << "Last Index of\n";
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "\n";

	cout << endl;
	return 0;
}