/*
String Rotation: Assume you have a method i5Substring which checks ifone word is a substring
of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one
call to isSubstring (e.g., Uwaterbottleuis a rotation ofuerbottlewatU ).
*/


#include<iostream>
#include<string>

using namespace std;

// My Solution
bool is_rotation_my(string str_1, string str_2) {

	if (str_1.length() != str_2.length())
		return false;

	int index = 0;
	while (index < str_1.length())
		if (str_1[index] != str_2[0])
			++index;
		else
			break;

	str_1.append(str_1.substr(0, index));
	return (str_1.find(str_2) != string::npos);
}

// Best Solution
bool is_rotation_best(string str_1, string str_2) {
	
	if (str_1.length() > 0 && (str_1.length() == str_2.length())) {
		// take any one string, append it with its on content, and then find the other string init.

		str_1.append(str_1);
		return (str_1.find(str_2) != string::npos);
	}
	return false;
}

int main() {

	// cout << (is_rotation_my("erbottlewat", "waterbottle") ? "Yes" : "No");
	cout << (is_rotation_best("waterbottle", "waterbottle") ? "Yes":"No");

	return 0;
}