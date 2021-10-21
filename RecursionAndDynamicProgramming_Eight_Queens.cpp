/*
Eight Queens: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board
so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all
diagonals, not just the two that bisect the board.
*/

#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

bool is_valid(tuple<int, int> my_pos, tuple<int, int> their_pos)				// this function checks if 'my_pos' is in diagonal of the 'their_pos'
{
	// if difference between my_pos.column and their_pos.column == difference between my_pos.row and their_pos.row, than they are in a diagnal

	int col_diff = abs(get<1>(my_pos) - get<1>(their_pos));
	int row_diff = abs(get<0>(my_pos) - get<0>(their_pos));

	if (col_diff == row_diff || get<0>(my_pos) == get<0>(their_pos) || get<1>(my_pos) == get<1>(their_pos))
		return false;

	return true;
}

void eight_queens(int curr_row, int curr_queen, vector<tuple<int, int>> positions)
{
	// base cases
	if (curr_row == 8)
	{
		cout << "Order\n\n";
		for (tuple<int, int> pos : positions)
		{
			cout << get<0>(pos) << ", " << get<1>(pos) << "\n";
		}

		return;
	}

	for (int i = 0; i < 8; ++i)				// traverse each column and find the right position to place the queen in a given row
	{
		bool found = true;

		if (positions.size() > 0)
		{
			// check all the positions and insert this queen to right location
			for (tuple<int, int> pos : positions)
			{
				tuple<int, int> my_pos(curr_row, i);
				if (is_valid(my_pos, pos) == false)				// not the correct position
				{
					found = false;
					break;
				}
			}
		}

		if (found == true)
		{
			positions.push_back(tuple<int, int>(curr_row, i));
			eight_queens(curr_row + 1, curr_queen + 1, positions);
			positions.pop_back();
		}
	}
}

void eight_queens()
{
	vector<tuple<int, int>> positions;
	eight_queens(0, 1, positions);
}

int main()
{
	eight_queens();

	cout << endl;
	return 0;
}