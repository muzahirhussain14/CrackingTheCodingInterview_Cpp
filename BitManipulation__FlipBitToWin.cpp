/*
	Flip Bit to Win: You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to
	find the length of the longest sequence of 1 s you could create.
	EXAMPLE
	Input:		1775	(or: 11011101111)
	Output:		8
*/

#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

int main()
{
	vector<int> zero_position;
	int numb = 1775;
	int count = 0;
	int sum = 0;
	int last = 0;
	cout << "numb: " << bitset<32>(numb) << "\n";


	while (numb != 0)
	{
		if (!(numb & 1))
			zero_position.push_back(count);

		++count;
		numb = numb >> 1;
	}

	count -= 1;
	for (int i = 0; i < zero_position.size(); ++i)
	{
		if (i + 1 < zero_position.size() && zero_position[i + 1] - last > sum)
			sum = zero_position[i + 1] - last;

		else if (i + 1 == zero_position.size() && count - last > sum)		// we have reached last zero
			sum = count - last;

		last = zero_position[i];
	}

	cout << "Count: " << count << "\n";
	cout << "Longest Sum: " << sum << "\n";
	//cout << "count: " << count << "\n";
	//cout << "numb: " << bitset<32>(numb) << "\n";

	for (int numb : zero_position)
		cout << numb << " ";

	cout << endl;
	return 0;
}