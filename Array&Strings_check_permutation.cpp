/*
Check Permutation: Given two strings of same length, write a method to decide if one string is a permutation of another.

A Permutation of a string is another string that contains same characters, only the order of characters can be different. 
For example, “abcd” and “dabc” are Permutation of each other.
*/


#include<iostream>
#include<map>
using namespace std;

bool is_permute(string& a, string& b) {

	if (a.length() != b.length())
		return false;

	map<char, int> charDict;

	for (char ch : a) {
		if (charDict.find(ch) != charDict.end())			// if char exists, increment its value
			charDict[ch]++;
		else
			charDict[ch] = 1;
	}

	for (char ch : b) {
		if ((charDict.find(ch) != charDict.end()) && charDict[ch] == 1)
			charDict.erase(ch);								// if we found a char and the count of the character is 1, remove it
		else
			charDict[ch] -= 1;
	}

	return (charDict.size() == 0);
}
int main() {

	string str_1 = "fcdce";
	string str_2 = "cdfzc";

	cout << (is_permute(str_1, str_2) ? "YES" : "NO");
	return 0;
}