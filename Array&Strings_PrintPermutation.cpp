/*
Given a string, print all its permutation.
Permutation is all possible combination of a string. 
*/

#include<iostream>
#include<string>

using namespace std;

void swap(string& str, int left, int right) {
	
	if (left >= 0 && right < str.length()) {
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;
	}
}

void permute(string str, int left, int right) {

	if (left >= right) {
		cout << str << "\n";
	}

	else {
		for (int i = left; i <= right; ++i) {
			swap(str, left, i);
			permute(str, left + 1, right);
			swap(str, left, i);							// fix the order - backtracking
		}
	}
}

int main() {

	string str = "ABC";
	permute(str, 0, str.length() - 1);

	return 0;
}