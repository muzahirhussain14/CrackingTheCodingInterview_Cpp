/*
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.

At first glance, this problem seems easy: just iterate through the matrix and every time we see a cell with
value zero, set its row and column to 0. There's one problem with that solution though: when we come
across other cells in that row or column, we'll see the zeros and change their row and column to zero. Pretty
soon, our entire matrix will be set to zeros.
One way around this is to keep a second matrix which flags the zero locations. We would then do a second
pass through the matrix to set the zeros. This would ta ke 0 (MN) space.

But here I would be creating my own data structure, that stores the location of all zeros in the matrix. Then another nested loop will go to those locations
and set row and columns in that location to 0.
However, run time of my solution is O(MN). It also involves some space complexity, because we are creating seperate vector and structure.
We can imporve this solution such that its space complexity is O(1).
*/


#include<iostream>
#include<vector>

using namespace std;

#define M	4
#define N	3


// utility
void print(int matrix[M][N]) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}

// My Solution
struct points {
	int x = -1;
	int y = -1;
};

void zeroMatrix_my(int matrix[M][N]) {

	vector<points> zero_locs;

	// getting the locations of all the 0 indexes
	for (int i = 0; i < M; ++i) {
		for(int j = 0; j<N; ++j)
			if (matrix[i][j] == 0) {
				points temp;
				temp.x = i; temp.y = j;
				zero_locs.push_back(temp);
			}
	}

	// write 0s to saved location
	for (points p : zero_locs) {
		for (int i = 0; i < N; ++i)			// write 0s to row
			matrix[p.x][i] = 0;

		for (int i = 0; i < M; ++i)			// Write 0s to column
			matrix[i][p.y] = 0;
	}
}



// Imporved Solution

void setRowZero(int matrix[M][N], int row) {
	for (int i = 0; i < N; ++i)
		matrix[row][i] = 0;
}

void setColumnZero(int matrix[M][N], int col) {
	for (int i = 0; i < M; ++i)
		matrix[i][col] = 0;
}

void zeroMatrix_improved(int matrix[M][N]) {

	bool first_row_zero = false;
	bool first_column_zero = false;

	// check if there are 0s in first row
	for (int i = 0; i < N; ++i)
		if (matrix[0][i] == 0) {
			first_row_zero = true;
			break;
		}

	// check of there are 0s in first column
	for(int i = 0; i<M; ++i)
		if (matrix[i][0] == 0) {
			first_column_zero = true;
			break;
		}


	// getting the locations of all the 0 indexes
	for (int i = 1; i < M; ++i) {
		for (int j = 1; j < N; ++j)
			if (matrix[i][j] == 0) {			// if you find 0, write 0 to first row and column of that location
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
	}

	// if you find 0 in the first column, write 0s to entire row
	for (int i = 0; i < M; ++i)
		if (matrix[i][0] == 0)
			setRowZero(matrix, i);

	// if you find a 0 in first row, write 0s to entire column of that position
	for (int i = 0; i < N; ++i)
		if (matrix[0][i] == 0)
			setColumnZero(matrix, i);


	if (first_row_zero)
		setRowZero(matrix, 0);

	if (first_column_zero)
		setColumnZero(matrix, 0);
}


int main() {

	int matrix[M][N] = {
		{1,2,0},
		{3,4,5},
		{6,0,7},
		{8,9,1}
	};

	zeroMatrix_improved(matrix);
	print(matrix);

	return 0;
}