/*
Assumption:	The input string will have all the distinct characters
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> permutation(string str)
{
	vector<string> result;

	if (str == "")
		result.push_back("");

	else
	{
		char first = str.at(0);
		vector<string> permutations = permutation(str.substr(1));

		for (string word : permutations)
		{
			for (int i = 0; i <= word.size(); ++i) 
			{
				string new_word = word;
				new_word.insert(new_word.begin() + i, first);
				result.push_back(new_word);
			}
		}
	}

	return result;
}

void print(vector<string> permutations)
{
	cout << "\n";
	for (string word: permutations)
	{
		cout << word << "\n";
	}

	cout << "\n";
}

int main()
{
	print(permutation("abcde"));

	cout << endl;
	return 0;
}