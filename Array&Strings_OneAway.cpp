/*
One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.

EXAMPLE
pale, pIe -> true
pales. pale -> true
pale. bale -> true
pale. bake -> false
*/

#include<iostream>
#include<string>

using namespace std;

bool countEdits(string a, string b, int diff) {

	bool flag = (diff) ? true:false;
	int b_index = 0;
	int edits = 0;

	for (int i = 0; i < a.length(); ++i){			// traverse on greater length
		
		if (edits >= 2)
			return false;

		if (a[i] != b[b_index]) {
			++edits;

			if (flag)				// don't increment b index if flag is set - need to move only bigger string here
				continue;
		}

		++b_index;
	}

	return true;
}

bool isOneEditAway(string a, string b) {

	int diff = std::abs(static_cast<int>(a.length() - b.length()));			// convert size_t to int

	if (diff >= 2)
		return false;

	else
		return (a.length() > b.length() ? countEdits(a, b, diff) : countEdits(b, a, diff));
}

int main() {

	cout << (isOneEditAway("geeks", "geeps") ? "Yes" : "No");

	return 0;
}