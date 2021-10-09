/*
Insertion: You are given two 32-bit numbers, Nand M, and two bit positions, i and j. Write a method
to insert Minto N such that M starts at bit j and ends at bit i. You can assume that the bits j through
i have enough space to fit all of M. That is, if M = 18811, you can assume that there are at least 5
bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully
fit between bit 3 and bit 2.

EXAMPLE
Input: N = 10000000000, M = 10011 , i = 2, j = 6
Output: N = 10001001100
*/


#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int i = 2;
	int j = 6;
	int N = 1024;
	int M = 19 << i;
	//cout << bitset<11>(N) << "\n";
	//cout << bitset<11>(M) << "\n";

	// Step 1 (Left Shift from -1 j times)
	int x = -1 << j+1;
	int y = (1 << i) - 1;

	int mask = (x | y);
	int m_reset = N & mask;
	//cout << bitset<11>(x) << "\n";
	//cout << bitset<11>(y) << "\n";
	cout << "M: " << bitset<11>(M) << "\n";
	cout << "Mask: " << bitset<11>(mask) << "\n";
	cout << "Reset M: " << bitset<11>(m_reset) << "\n";
	cout << "Final: " << bitset<11>(m_reset | M) << "\n";

	cout << "\n";
	return 0;
}