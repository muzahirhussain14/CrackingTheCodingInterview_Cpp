/*
Next Number: Given a positive integer, print the next smallest and the next largest number that
have the same number of 1 bits in their binary representation.
*/


#include <iostream>
#include <bitset>

using namespace std;

int target_count = 0;

int count_ones(int n)
{
	int count = 0;
	while (n != 0)
	{
		if (n & 0x01)
			++count;

		n >>= 1;
	}

	return count;
}

int main()
{
	int number = 13948;
	target_count = count_ones(number);

	bool found_min = false, found_max = false;
	int min = number - 1;
	int max = number + 1;
	while (1)
	{
		if (!found_min && count_ones(min--) == target_count)
			found_min = true;

		if (!found_max && count_ones(max++) == target_count)
			found_max = true;

		if (found_max && found_min)
			break;
	}

	cout << "Target: " << number << "  " << bitset<32>(number) << "\n";
	cout << "Next Lower Number: " << min + 1 << "  " << bitset<32>(min + 1) << "\n";
	cout << "Next Greater Number: " << max - 1 << "  "  << bitset<32>(max - 1) << "\n";

	cout << endl;
	return 0;
}