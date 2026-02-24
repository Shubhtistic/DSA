#include <iostream>
#include <stack>
using namespace std;

// Problem Statement
/*Given two strings s and t,
return true if they are equal when both are typed into empty text editors.
'#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".*/

// Simple Approach
/*We simply have to remove characters whenever we encouter #
i.e remove one char before # if there are two ## remove two chars before these two
so what we can do is we can use a temp string or stack
what we will do simply is start from front and whenever we hit # remove the last element we entered
we will do this until the end and then at last compare the two temp strings or the two stacks whichever you used
Note: we are using temp strings for simplicity same can be acchieved with stacks*/

// T.C -> O(n+m)
// T.S -> O(n+m)

bool backspaceCompare_brute(string s, string t)
{

    string temp_s = "";
    string temp_t = "";

    for (char it : s)
    {
        if (it != '#')
        {
            temp_s = temp_s + it;
        }
        else if (!temp_s.empty())
        {
            temp_s.pop_back();
        }
    }

    for (char it : t)
    {
        if (it != '#')
        {
            temp_t = temp_t + it;
        }
        else if (!temp_t.empty())
        {
            temp_t.pop_back();
        }
    }
    // cout<<temp_t<<" "<<temp_s;
    return temp_t == temp_s;
}

// Two Pointer Approach
/*We can start two seperate pointers both from the back what that does is
if we encounter a hash(#) we can just skip the char besides it and we do this for both strings while comparing them
if there are multiple hashes one by one we can also clear that by counting the total hashes and then moving back that many times
*/

// T.C -> O(n+m)
// S.C -> O(1)

bool backspaceCompare_optimal(string s, string t)
{

    int s_hash = 0;
    int t_hash = 0;

    int i = s.size() - 1;
    int j = t.size() - 1;

    // we will continue until both string are processed
    while (i >= 0 || j >= 0)
    {

        // move i to next valid char
        while (i >= 0)
        {

            if (s[i] == '#')
            { // if we found a backspace
                s_hash++;
                i--;
            }
            else if (s_hash > 0)
            {
                s_hash--;
                i--;
            }
            else
            {
                break;
            }
        }

        // now move j to next valid char
        while (j >= 0)
        {

            if (t[j] == '#')
            {
                t_hash++;
                j--;
            }
            else if (t_hash > 0)
            {
                t_hash--;
                j--;
            }
            else
            {
                break;
            }
        }

        // now lets compare the chars in each string
        if (i >= 0 && j >= 0)
        {
            if (s[i] != t[j])
            { // mismatch
                return false;
            }
        }
        else // this runs only if the above 'if' statement was wrong
        {
            // one of them is invalid
            // we have to find only one string has characters left
            // not both if both are -ve then it means we were successful
            if (i >= 0 or j >= 0)
            {
                return false;
            }
        }

        i--;
        j--;
    }

    return true; // all characters matched
}

int main()
{

    return 0;
}