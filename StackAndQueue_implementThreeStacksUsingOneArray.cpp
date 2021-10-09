/*
Three in One: Describe how you could use a single array to implement three stacks

Solution:
This idea is to use three pointer for three stack. One stack grows from the start of the array, Second stack grows from the end to left, and 
finally the third starck grows from middle to any direction you want.

If any of the two stacks (start and end) collide the middle stack, shift the middle stack to the next position if you have space.
*/

#define LEFT	0
#define RIGHT	1

#include<iostream>
using namespace std;

class Stacks {

private:
	const int SIZE;
	int* stack;
	int first_stack;						// starts from front of array
	int second_stack;						// starts from end of array, making its way backwards
	int third_stackStart;					// start from mid to right
	int third_stackEnd;

	bool shiftMidStack(int direction) {		// direction

		if (direction == LEFT) {			// shift mid stack to left

			// First check if size if full
			if (first_stack == third_stackStart)
				return false;
	
			for (int i = third_stackStart - 1; i < third_stackEnd-1; ++i)				// shifting middle stack to left
				stack[i] = stack[i + 1];
		
			// move pointers one step back now.
			--third_stackStart;
			--third_stackEnd;
		}

		else if (direction == RIGHT) {		// shift mid stack to right

			// First check if size if full
			if ((third_stackEnd + 1) == second_stack)
				return false;

			for (int i = third_stackEnd; i > third_stackStart; --i)
				stack[i] = stack[i - 1];

			// move pointers one step forward now
			++third_stackStart;
			++third_stackEnd;
		}

		return true;						// return true if you were able to shift, else return false
	}

public:
	Stacks(int size) :SIZE(size) {
		stack = new int[SIZE];
	
		first_stack = 0;
		second_stack = SIZE-1;
		third_stackStart = third_stackEnd = SIZE / 2;
	}


	void push(int value, int stack_no) {

		// stack_no can be 1, 2, or 3 - representing the stack where we want to insert the value

		if (stack_no == 1)
		{
			if (!(first_stack < third_stackStart))
			{
				if (!shiftMidStack(RIGHT))
					return;
			}
			stack[first_stack++] = value;
		}

		else if (stack_no == 2) 
		{
			if (!(second_stack >= third_stackEnd))
			{
				if (!shiftMidStack(LEFT))
					return;
			}
			stack[second_stack--] = value;
		}

		else if (stack_no == 3) 
		{
			if (!(third_stackEnd < second_stack))
			{
				if (!shiftMidStack(LEFT))
					return;
			}
			stack[third_stackEnd++] = value;
		}
	}

	int pop(int stack_no) {

		if (stack_no == 1 && first_stack > 0)
			return stack[--first_stack];

		else if (stack_no == 2 && second_stack < SIZE)
			return stack[++second_stack];

		else if (stack_no == 3 && third_stackEnd >= third_stackStart)
			return stack[--third_stackEnd];
	}

	void print(int stack_no) 
	{
		if (stack_no == 1) 
		{
			int ptr = first_stack;
			while (ptr > 0)
				cout << stack[--ptr] << " ";
		}
		
		else if (stack_no == 2)
		{
			int ptr = second_stack;
			while (ptr < SIZE-1)
				cout << stack[++ptr] << " ";
		}

		else if(stack_no == 3)
		{
			int ptr = third_stackEnd;
			while(ptr > third_stackStart)
				cout << stack[--ptr] << " ";
		}

		cout << "\n";
	}
};


int main() {

	Stacks stack(6);
	stack.push(10, 1);
	//stack.push(9, 1);
	stack.push(8, 3);

	stack.push(7, 2);
	stack.push(6, 2);

	stack.push(3, 3);
	stack.push(4, 3);

	cout << "First Stack: ";
	stack.print(1);

	cout << "\nSecond Stack: ";
	stack.print(2);

	cout << "\nThird Stack: ";
	stack.print(3);


	cout << "Press any key to continue\n";
	cin.get();
	return 0;
}