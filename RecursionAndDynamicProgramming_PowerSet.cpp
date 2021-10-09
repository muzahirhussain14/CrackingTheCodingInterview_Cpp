#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> powerset(int arr[], int size, int index=0)
{
	vector<vector<int>> result;

	if (index == size)
	{
		vector<int> _;
		result.push_back(_);
	}
	else
	{
		vector<vector<int>> return_val = powerset(arr, size, index + 1);
		for (int i = 0; i < return_val.size(); ++i)
		{
			vector<int> orignal = return_val[i];
			vector<int> appended = orignal;
			appended.insert(appended.begin(), arr[index]);

			result.push_back(orignal);
			result.push_back(appended);
		}
	}

	return result;
}

void print_result(vector<vector<int>> x)
{
	cout << "\n";
	for (int i = 0; i < x.size(); ++i)
	{
		for(int j = 0; j < x[i].size(); ++j)
			cout << x[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	const int size = 3;
	int arr[size] = { 1,2,3 };

	print_result(powerset(arr, size));

	cout << "Done";
	cout << endl;
	return 0;
}