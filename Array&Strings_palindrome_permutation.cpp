/*
Palindrome Permutation : Given a string, write a function to check if it is a permutation of
a palindrome.A palindrome is a word or phrase that is the same forwards and backwards.A
permutation is a rearrangement of letters.The palindrome does not need to be limited to just
dictionary words.
EXAMPLE
Input : Tact Coa
Output : True(permutations : "taco cat'; "atco cta'; etc.)

In a palindrome or palindrome permutation, we would have all even characters except 1 (if the length is odd, middle character will be a odd character).

For this problem, lets assume that we are NOT allowed to use any data structure. If we were allowed to use the datastructure,
we could easily use dictionary or stack to push the character in to it. When we get the same character again, we would either pop it form stack
or we would decrement count in dictionary.
In the end we would either have 0 or 1 character in the dictionary or stack, depending upon even or odd length.
*/

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome_permutation(string str) {

	const int SIZE = str.length();
	bool* matched = new bool[SIZE];

	for (int i = 0; i < SIZE; ++i)
		matched[i] = false;

	for (int i = 0; i < SIZE - 1; ++i) {

		if (matched[i])				// if already matched, no need to compare again.
			continue;

		for (int j = i + 1; j < SIZE; ++j) {
			if (matched[j] == false && str[i] == str[j]) {
				matched[j] = true;
				matched[i] = true;
				break;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < SIZE; ++i)
		if (matched[i] == false)
			count++;

	delete[] matched;
	return ((count == 0) || (count == 1));
}

void pre_process(string& str) {		// remove space, make case smaller etc
	
	const int SIZE = str.length();
	int no_spaces = 0;

	for (int i = 0; i < str.length(); ++i)
		if (str[i] == ' ')
			no_spaces++;

	int counter = no_spaces;

	while (counter > 0) {
		for (int i = 0; i < SIZE - 1; ++i) {

			if (str[i] == ' ') {
				for (int j = i + 1; j < SIZE; ++j)
					str[i++] = str[j];
			}
		}
		--counter;
	}
	str.erase((str.length() - no_spaces), str.length());
}

int main() {

	string str = "zxyxzyx";	 

	pre_process(str);
	cout << (is_palindrome_permutation(str) ? "True" : "False");

	return 0;
}