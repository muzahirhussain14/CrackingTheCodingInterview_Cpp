#include <iostream>
#include <vector>
using namespace std;


void print_spiralMatrix(const vector<vector<int>>& matrix)
{
	int start_row = 0, start_col = 0;
	int end_row = matrix.size() - 1, end_col = matrix[0].size() - 1;
	int count = matrix.size() * matrix[0].size();							// m * n

	cout << "Count: " << count << "\n";

	while (start_row <= end_row && start_col <= end_col)
	{
		for (int i = start_col; i <= end_col; ++i) {
			cout << matrix[start_col][i] << " ";
			--count;
		}

		if (count == 0)
			break;

		for (int j = start_row + 1; j <= end_row; ++j) {
			cout << matrix[j][end_col] << " ";
			--count;
		}


		if (count == 0)
			break;

		for (int k = end_col - 1; k >= start_col; --k) {
			cout << matrix[end_row][k] << " ";
			--count;
		}

		if (count == 0)
			break;

		for (int i = end_row - 1; i > start_row; --i) {
			cout << matrix[i][start_col] << " ";
			--count;
		}

		if (count == 0)
			break;

		start_row += 1;		start_col += 1;
		end_row -= 1;		end_col -= 1;
	}
}

int main()
{
	vector<vector<int>> matrix;

	vector<int> temp;
	for (int i = 1; i <= 16; ++i)
	{
		temp.push_back(i);

		if (i % 4 == 0)
		{
			matrix.push_back(temp);
			temp.clear();
		}
	}

	for (vector<int> x : matrix) 
	{
//		for (int i : x)
//			cout << i << " ";

//		cout << "\n";
	}

	print_spiralMatrix(matrix);

	cout << endl;
	return 0;
}