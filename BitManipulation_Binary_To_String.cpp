/*
Binary to String: Given a real number between 8 and 1 (e.g., 0.72) that is passed in as a double,
print the binary representation. If the number cannot be represented accurately in binary with at
most 32 characters, print "ERROR"
*/

#include<iostream>
#include<string>
using namespace std;


string binary_representation_of_real_number(double number)
{
	if (number < 0.0 || number > 1.0)
		return "";

	string result = "";

	while (number > 0)
	{
		if (result.size() > 32)
			return "ERROR\n";

		double r = number * 2;

		if (r >= 1) 
		{
			result.append("1");
			number = r - 1;
		}
		else
		{
			result.append("0");
			number = r;
		}
	}

	return result;
}

int main()
{
	//double n = 0.625;
	//double n = 0.75;
	//double n = 0.3;
	double n = 1.0;
	cout << binary_representation_of_real_number(n) << "\n";
	cout << endl;
	return 0;
}