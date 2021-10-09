#include<iostream>
#include <unordered_map>

using namespace std;


int triple_step(int steps, unordered_map<int, int>& memo)
{
	if (memo.find(steps) != memo.end())
		return memo[steps];

	if (steps == 0)
		return 1;

	else if (steps < 0)
		return 0;

	int result = triple_step(steps - 1, memo) + triple_step(steps - 2, memo) + triple_step(steps - 3, memo);
	memo[steps] = result;

	return result;
}

int triple_step(int steps)
{
	unordered_map<int, int> memo;
	return triple_step(steps, memo);
}

int main()
{
	cout << "Total Posible Steps: " << triple_step(5) << "\n";


	cout << endl;
	return 0;
}