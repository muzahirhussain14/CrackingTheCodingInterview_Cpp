/*
Parens: Implement an algorithm to print all valid (Le., properly opened and closed) combinations
of n pairs of parentheses.
*/

#include <iostream>
#include <string>
using namespace std;

void parens(int open_bracket_count, int close_bracket_count, string result)
{
	if (open_bracket_count < 0 || close_bracket_count < open_bracket_count)							// invalid state
		return;

	if (open_bracket_count == 0 && close_bracket_count == 0)
		cout << result << "\n";

	else
	{
		result.append("(");
		parens(open_bracket_count - 1, close_bracket_count, result);

		result.pop_back();
		result.append(")");
		parens(open_bracket_count, close_bracket_count - 1, result);
	}
}

void parens(int n)
{
	parens(n, n, "");
}

int main()
{
	parens(3);

	cout << endl;
	return 0;
}