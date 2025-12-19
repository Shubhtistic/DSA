// problem statement
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/

// we can use the two pointers approach
/*
Basically take two pointers one at start and one at the end and compare one by one and increase/decrease
each pointer based on comparison. For non-alphanumeric values increase/decrease that pointer without
comparison i.e skip that character

*/

// T.C -> O(n)
// S.C -> O(1)

#include <iostream>
#include <cctype>
using namespace std;

bool valid_palindrome(string &s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start <= end)
    {
        if (!isalnum(s[start]))
        {
            start++;
        }
        else if (!isalnum(s[end]))
        {
            end--;
        }
        else
        {
            if (tolower(s[start]) == tolower(s[end]))
            {

                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string s = "Shubham";
    if (valid_palindrome(s))
    {
        cout << "yes";
    }
    else
        cout << "no";

    return 0;
}