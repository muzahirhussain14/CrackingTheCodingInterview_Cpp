/*
Write a method to compute all the permutations of a string whose characters are not necessarily	unique. The list of permutations should 
not have duplicates.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void get_permutation(unordered_map<char, int>& map, string prefix, int length, vector<string>& result)
{
	if (length == 0)
	{
		result.push_back(prefix);
		return;
	}

	for (auto entry : map)
	{
		if (entry.second > 0)					// if value is greater then 0
		{
			int count = entry.second;
			map[entry.first] = count - 1;
			get_permutation(map, prefix + entry.first, length - 1, result);
			map[entry.first] = count;
		}
	}
}

vector<string> get_permutations(string word)
{
	unordered_map<char, int> map;
	vector<string> result;

	for (char ch : word)
	{
		if (map.find(ch) != map.end())
		{
			int count = map[ch];
			map[ch] = ++count;
		}
		else
		{
			int count = 1;
			map[ch] = count;
		}
	}
	
	get_permutation(map, "", word.length(), result);
	return result;
}

int main()
{
	string x = "aabca";
	vector<string> result = get_permutations(x);
	
	for (string x : result)
	{
		cout << x << "  " << "\n";
	}


	cout << endl;
	return 0;
}