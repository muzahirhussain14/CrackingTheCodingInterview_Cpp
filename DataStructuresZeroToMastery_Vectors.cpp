#include <iostream>
#include <vector>

using namespace std;

int main()
{
//	vector<int> myVec(10, 5);										// Initialization
	vector<int> myVec;

	for (int i = 0; i < 10; ++i)
	{
		cout << "Capacity: " << myVec.capacity() << "\n";
		cout << "Size: " << myVec.size() << "\n";
		myVec.push_back(i);
	}

	cout << myVec.at(2) << " " << myVec[2] << "\n";					// at returns the element at the index, we can also use square brackets, but at() is a safer approach.
	
	cout << "Size Before Pop: " << myVec.size() << "\n";
	myVec.pop_back();												// removes the last element from the vector.
	cout << "Size After Pop: " << myVec.size() << "\n";


	cout << endl;
	return 0;
}