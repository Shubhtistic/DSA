#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

// Problem Statement
/*Given two strings s and t of lengths m and n respectively,
return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/

// Sliding Window Approach
/*What this question expects us do is find such a minm window from string 's' such that it contains all leters from string 't'
So a very simple Approach we can follow is use an array of size 256 to hold all the alphabets for string t
what that does is gives us a very easy way to find if the charrs from t are present in 's' or not
after that what we do is we shrink window and again see if that window is valid or not*/

bool fnd(vector<int> &have, vector<int> &need)
{
    for (int i = 0; i < 256; i++)
    {
        if (have[i] < need[i])
        {
            // if something we need is not present in 'have array' even frequency should also be same if not
            // its not valid
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t)
{

    vector<int> have(256, 0);
    vector<int> need(256, 0);

    // we will fill the "need array" with all its chars with its chars
    for (int i = 0; i < t.size(); i++)
    {
        need[t[i]]++;
    }
    // This required O(n) time. n-> size of 'string t'

    int start = -1;
    int low = 0;
    int high = 0;
    int res = INT_MAX;
    // res stores length of smallest window we have so far
    for (int high = 0; high < s.size(); high++)
    {
        // note what we have
        have[s[high]]++;

        while (fnd(have, need))
        {
            int len = high - low + 1;

            if (len < res)
            // if we find new length smaller than old res -> new minm length

            {
                res = len;
                start = low;
                // the starting point -> later used to build substring }
            }
            have[s[low]]--;
            // we will try to shrink to still see we can make it smaller
            low++;
        }
    }

    if (res == INT_MAX)
    {
        return "";
    }
    return s.substr(start, res);
}

// T.C -> O(n+m)
// S.C -> O(256+256) -> STILL CONSTANT SPACE USED! .. O(1)

int main()
{

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Example 1: " << minWindow(s1, t1) << endl;

    string s2 = "a";
    string t2 = "a";
    cout << "Example 2: " << minWindow(s2, t2) << endl;

    string s3 = "a";
    string t3 = "aa";
    cout << "Example 3: " << minWindow(s3, t3) << endl;

    return 0;
}