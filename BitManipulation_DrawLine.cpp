#include<iostream>
using namespace std;


void drawline(char screen[], int width, int x1, int x2, int y)
{
	int start_offset = x1 % 8;
	int first_full_byte = x1 / 8;

	if (first_full_byte != 1)
		++first_full_byte;


	int end_offset = x1 % 8;
	int end_full_byte = x2 / 8;

	if (end_full_byte != 7)
		--end_full_byte;

	for (int b = first_full_byte; b <= end_full_byte; ++b)
	{
		screen[(width / 8) * y + b] |= 0xff;
	}

	char start_mask = 0xff >> start_offset;
	char end_mask = ~(0xff >> (end_offset + 1));

	if ((x1 / 8) == (x2 / 8)) {									// if both x1 and x2 are in the same byte
		char mask = (start_mask & end_mask);
		screen[(width / 8) * y + (x1 / 8)] |= mask;
	}
	else
	{
		if (start_offset != 0) {
			int byte_number = (width / 8) * y + first_full_byte - 1;
			screen[byte_number] |= start_mask;
		}
		
		if (end_offset != 7) {
			int byte_number = (width / 8) * y + end_full_byte + 1;
			screen[byte_number] |= end_mask;
		}
	}

}

int main()
{

	cout << endl;
	return 0;
}