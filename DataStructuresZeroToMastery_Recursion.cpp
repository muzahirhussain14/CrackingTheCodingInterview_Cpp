#include<iostream>
using namespace std;


int power(int number, int pow)
{
	if (pow == 0)
		return 1;

	int result = power(number, pow - 1);

	return result * number;
}

int fib(int number)
{
	if (number == 0)
		return 0;

	if (number == 1)
		return 1;

	return fib(number - 1) + fib(number - 2);
}

int sum_of_digits(int number)
{
	if (number == 0)
		return 0;

	int mod = number % 10;
	return mod + sum_of_digits(number / 10);
}

int multiplication(int x, int y)
{
	if (x == 0)
		return 0;

	int result = multiplication(x - 1, y);

	return y + result;
}

int count_zero(int numb)
{
	if (numb == 0)
		return 0;

	int count_zeros = count_zero(numb/10);

	if (numb % 10 == 0)
		return count_zeros + 1;
	else
		return count_zeros;
}

int main()
{
	// Power using Recursion
	cout << "\nPower using Recursion: " << power(2, 3);
	cout << "\nFibonacci Series: " << fib(8);
	cout << "\nSum of digits: " << sum_of_digits(12345);
	cout << "\nMultiplcation: " << multiplication(30, 15);
	cout << "\nCount Zero: " << count_zero(200030);

	cout << endl;
	return 0;
}