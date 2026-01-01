#include <iostream>
#include <cctype>
using namespace std;

// Problem statement
/* A string can be shortened by replacing any number of non-adjacent,
non-empty substrings with their lengths (without leading zeros).
For example, the string "implementation" can be abbreviated in several ways, such as:

"i12n" -> ("i mplementatio n")
"imp4n5n" -> ("imp leme n tatio n")
"14" -> ("implementation")
"implemetation" -> (no substrings replaced)
Invalid abbreviations include:

"i57n" -> (i mplem entatio n, adjacent substrings are replaced.)
"i012n" -> (has leading zeros)
"i0mplementation" (replaces an empty substring)
You are given a string named word and an abbreviation named abbr, return true if abbr correctly abbreviates word, otherwise return false.

A substring is a contiguous non-empty sequence of characters within a string.

Example 1:
Input: word = "apple", abbr = "a3e"
Output: true

Example 2:
Input: word = "international", abbr = "i9l"
Output: false

Example 3:
Input: word = "abbreviation", abbr = "abbreviation"
Output: true

*/

// Two Pointer Approach
/* we can comapare both the word and the abbreviation given to us using individual pinters for both
we compare the chars and when we hit an number we construct that number and move the word pointer that many times
if at the end both pointers are exhausted and eqaul to each other then we can say that its an valid word abbreviation */

// T.C -> O(n+m)
// S.C -> O(1)

bool validWordAbbreviation(string word, string abbr)
{
    int i = 0;
    int j = 0;

    while (i < word.size() && j < abbr.size())
    {

        if (isdigit(abbr[j]))
        {
            if (abbr[j] == '0') // to check if number starts with zero
            {
                return false;
            }
            int current = 0;
            while (j < abbr.size() && isdigit(abbr[j])) // to construct the number
            {
                current = current * 10 + (abbr[j] - '0');
                // (abbr[j]-'0'); -> Safe and easy way to convert to a number
                j++;
            }
            i = i + current;
            // add the number onto the i pointer to skip those number of characters

            if (i > word.size())
            {
                return false;
                // early exist if the digit makes 'i' exceed word size
            }
        }

        if (word[i] != abbr[j])
        {
            return false;
        }
        else
        {
            i++;
            j++;
        }
    }

    // we check if both pointers are past both the word and its abbreviation
    // is both are equal to their respecive strings we can conclude the string was an valid abbreviation

    return i == word.size() && j == abbr.size();
}

int main()
{
    string word = "apple";
    string abbr = "a3e";

    if (validWordAbbreviation(word, abbr))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Not valid";
    }
    return 0;
}