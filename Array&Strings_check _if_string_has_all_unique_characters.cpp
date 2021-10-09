/*
Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?
*/
#include <iostream>
#include <string>

using namespace std;

// solution 1 - Use a boolean array of size string and store each character at the index of the size after mod operation
bool check_unique(string str) {

    // there are 256 (0-255) unique characters in ASCII set (This is valid if ascii character size is 8 bit). 
    // If ascii set is 7 bit long then you have 128 unique characters)
    const int length = 256;
    bool occurrence[length];

    for (int i = 0; i < length; ++i)
        occurrence[i] = false;

    // need ascii value, thus reading the string as 'int' ch
    for (int ch : str) {
        if (occurrence[ch])
            return false;

        else
            occurrence[ch] = true;
    }

    return true;
}


// solution 2 - Use bit wise operations to determine if a character is repeated or not.
// For this lets assume our characters are in range from a-z.
// We use int, map each character to a single bit of this int variable, which is 'collector'.
bool check_unique_2(string str) {

    int collector = 0;

    for (int ch : str) {
        int val = ch - 65;

        if ((collector & (1 << val)) > 0)
            return false;

        collector |= (1 << val);
    }
    return true;
}

int main()
{
    cout << (check_unique_2("axybdzw") ? "True\n" : "False\n");

    return 0;
}