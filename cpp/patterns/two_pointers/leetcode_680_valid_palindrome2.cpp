#include <iostream>
using namespace std;

/*Given a string s, return true if the s can be palindrome
 after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.*/

// Brute force approach
/* we can make an seperate function whose only task is to check whether an string palindrome or not.
and in the main function we will loops to construct an string(everytime one unique char is deleted),
and check for every string individually.
If any string is palindrome we return true.
*/

// T.C -> O(n^2)
// S.C -> O(1)

bool ispal1(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool validPalindrome1(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        string cp = "";

        for (int j = 0; j < s.size(); j++)
        {
            if (j == i)
            {
                continue;
            }
            cp = cp + s[j];
        } // runs o(n) time

        if (ispal1(cp))
        {
            return true;
        } // runs o(n-1) times

        // so for every iteration of outer loop its
        // O(n) -> building string + O(n-1) comparing the string
        // every iteration O(1) x O(n)
        // outer loop runs n times
        // So Total T.C is O(n^2)
    }
    return false;
}

// Optimal(Time Efficient Approach)
/* we kind of follow the structure we used in brute force but approach is different
we check for palindrome using the helper function but when the two elements are not same, we then use
the helper function to check if that certain part is an valid palindrome (by removing only one char.) */

// T.C -> O(n)
// S.C -> O(1)

bool ispal2(const string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool validPalindrome2(string s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            // skip either left or right character once
            return ispal2(s, start + 1, end) ||
                   ispal2(s, start, end - 1);
        }
    }
    return true;
}

int main()
{
    string test = "aabaa";
    if (validPalindrome1(test))
    {
        cout << test << " is palindrome\n";
    }

    if (validPalindrome2(test))
    {
        cout << test << " is palindrome\n";
    }

    return 0;
}