#include<iostream>
using namespace std;

void permutation(char arr[], int i)
{
	if (arr[i] == '\0') 
	{
		cout << arr << "\n";
		return;
	}

	for (int j = i; arr[j] != '\0'; ++j) 
	{
		swap(arr[i], arr[j]);
		permutation(arr, i + 1);
		swap(arr[i], arr[j]); 
	}
}

int main()
{
	char arr[15];
	cout << "Arr: ";
	cin >> arr;

	permutation(arr, 0);

	//swap(arr[0], arr[2]);
	//cout << arr << "\n";

	cout << endl;
	return 0;
}