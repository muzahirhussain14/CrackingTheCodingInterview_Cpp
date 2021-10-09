#include <iostream>
#include <string>
using namespace std;

int power(int numb, int pow)
{
	if (pow == 0)
		return 1;

	if (pow == 1)
		return numb;

	return power(numb, pow - 1) * numb;
}

int convert_str_to_int(string number)
{
	if (number.length() == 1)
	{
		return atoi(number.c_str()) * power(10, 0);
	}

	int result = convert_str_to_int(number.substr(1, number.length()));
	int nextDigit = number.front() - '0';


	return nextDigit * power(10, (number.length() - 1)) + result;
}

int main()
{
	string a = "1234";
	cout << a.substr(1, a.length()) << "\n";
	cout << "Front: " << a.front() << "\n";

	cout << "convert_str_to_int: " << convert_str_to_int("2525");

	cout << endl;
	return 0;
}