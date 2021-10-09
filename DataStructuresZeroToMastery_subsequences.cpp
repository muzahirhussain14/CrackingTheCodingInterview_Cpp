#include <iostream>
using namespace std;

void print_subsequence(char arr[], string output)
{
	if (arr[0] == '\0')
	{
		cout << output << "\n";
		return;
	}

	print_subsequence(arr + 1, output);
	print_subsequence(arr + 1, output + arr[0]);
}

int main()
{
	char arr[15];
	cout << "Enter word: ";
	cin >> arr;

	print_subsequence(arr, "");


	cout << endl;
	return 0;
}