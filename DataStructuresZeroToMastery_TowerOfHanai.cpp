#include<iostream>
using namespace std;

int step_towerOfHanai(int n) 
{
	if (n == 0)
		return 0;

	return step_towerOfHanai(n - 1) + 1 + step_towerOfHanai(n - 1);
}

void print_towerOfHanai(int n, char from, char helper, char dest)
{
	if (n == 0)
		return;

	print_towerOfHanai(n - 1, from, dest, helper);
	cout << "Moving " << n << " from " << from << " to " << dest << "\n";
	print_towerOfHanai(n - 1, helper, from, dest);
}

int main()
{
	cout << "Steps for Tower of Hanai: " << step_towerOfHanai(5) << "\n";
	cout << "Printing Tower of Hanai: \n";
	print_towerOfHanai(3, 'A', 'B', 'C');

	cout << endl;
	return 0;
}