#include<iostream>
using namespace std;

int robot_in_a_grid(int x, int y, int size) 
{
	if (x >= size || x < 0)
		return;

	if (y >= size || y < 0)
		return;

	if ("offlimit")
		return;

	robot_in_a_grid(x + 1, y, size) || robot_in_a_grid(x, y + 1, size); 
}

int main()
{


	cout << endl;
	return 0;
}