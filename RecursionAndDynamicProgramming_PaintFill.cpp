/*
PaintFill:
Implement a paint_fill() method that takes in a screen(represented by a 2D array of colors), a point, and a new color, fill in the surrounding area
until the color changes from the orignal color. 
*/

#include<iostream>
using namespace std;

const int LENGTH_Y = 5;

void fill_paint(char screen[][LENGTH_Y], int length_x, int point_x, int point_y, char ocolor, char ncolor)
{
	if (point_x >= length_x || point_y >= LENGTH_Y)
		return;

	if (point_x < 0 || point_y < 0)
		return;

	if (screen[point_x][point_y] == ncolor)
		return;

	if (screen[point_x][point_y] == ocolor)
	{
		screen[point_x][point_y] = ncolor;
		fill_paint(screen, length_x, point_x + 1, point_y, ocolor, ncolor);
		fill_paint(screen, length_x, point_x, point_y + 1, ocolor, ncolor);
		fill_paint(screen, length_x, point_x - 1, point_y, ocolor, ncolor);
		fill_paint(screen, length_x, point_x, point_y - 1, ocolor, ncolor);
	}
}

void fill_paint(char screen[][LENGTH_Y], int length_x, int point_x, int point_y, char color)
{
	fill_paint(screen, length_x, point_x, point_y, screen[point_x][point_y], color);
}


void print_screen(char screen[][LENGTH_Y], int length_x)
{
	for (int i = 0; i < length_x; ++i)
	{
		for (int j = 0; j < LENGTH_Y; ++j)
			cout << screen[i][j] << " ";

		cout << "\n";
	}
	cout << "\n";
}

int main()
{

	char arr[5][LENGTH_Y] = { {'w', 'w', 'w', 'r', 'r'},
					   {'g', 'w', 'g', 'g', 'r'},
					   {'g', 'w', 'g', 'g', 'r'},
					   {'g', 'w', 'g', 'g', 'r'},
					   {'w', 'w', 'w', 'g', 'r'} };

	print_screen(arr, 5);
	fill_paint(arr, 5, 1, 1, 'b');						// replace white with blue
	print_screen(arr, 5);

	cout << endl;
	return 0;
}