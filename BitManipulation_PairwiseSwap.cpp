/*
Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
*/

#include <iostream>
#include<bitset>

using namespace std;

int pairwise_bits_swap(int numb)
{
	//cout << "Odd bits: " << bitset<32>((numb & 0xAAAAAAAA) >> 1) << "\n";
	//cout << "Even bits: " << bitset<32>((numb & 0x55555555) << 1) << "\n";

	return ((numb & 0xAAAAAAAA) >> 1) | ((numb & 0x55555555) << 1);
}

int main()
{
	int number = 5;
	cout << "Number: " << bitset<32>(number) << "\n";
	cout << "After Bitwise Swap: " << bitset<32>(pairwise_bits_swap(number)) << "\n";

	cout << endl;
	return 0;
}