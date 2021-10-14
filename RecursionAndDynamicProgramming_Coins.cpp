/*
Given an infinite number of quaters (25 cents), dimes (10 cents), nickels (5 cents), and pennis (1 cent), write a 
code to calculate number of ways of representing n cents.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int coins(int n, unordered_map<int, int>& memo)
{
	if (n == 0)
		return 1;

	if (n < 0)
		return 0;

	if (memo.find(n) != memo.end())
		return memo[n];

	memo[n] = coins(n - 25, memo) + coins(n - 10, memo) + coins(n - 5, memo) + coins(n - 1, memo);
	return memo[n];
}

int coins(int n)
{
	unordered_map<int, int> memo;
	return coins(n, memo);
}

int main()
{
	cout << coins(5) << "\n";

	cout << endl;
	return 0;
}