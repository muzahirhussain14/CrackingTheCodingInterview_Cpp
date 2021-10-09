/*
Conversion: Write a function to determine the number of bits you would need to flip to convert
integer A to integer B.
EXAMPLE
Input:		29 (or: 111(1), 15 (or: (1111)
Output:		2
*/


#include <iostream>
using namespace std;

int conversion_using_rightShift(int n1, int n2)
{
	int n = n1 ^ n2;						// // xor -> 0 when bits are same, 1 when bits are different. We can now simply count numbers of 1s in the xored value
	int count = 0;

	for (;n != 0; n >>= 1)					
	{
		count += n & 1;
	}

	return count;
}

int conversion_using_flipping(int n1, int n2)
{
	// instead if right shifting, we can continuously flip the least significant bit and count how long it takes c to reach 0.The operation c = c & (c - 1) will clear the least significant bit in c.
	int n = n1 ^ n2;
	int count = 0;

	for (; n != 0; n = n & (n - 1))
		++count;

	return count;
}

int main()
{
	cout << "\nconversion_using_rightShift(29, 15): " << conversion_using_rightShift(29, 15);
	cout << "\nconversion_using_flipping(29, 15): " << conversion_using_flipping(29, 15);

	cout << endl;
	return 0;
}