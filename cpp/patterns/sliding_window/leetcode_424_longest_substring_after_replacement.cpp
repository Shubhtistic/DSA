#include <iostream>
#include <vector>

using namespace std;

// Problem Statement
/*  You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

// What Does problem actually say
/*We are given string we find to out such a substring where after replacing k chars the entire substring has the same chars
So this is like a longest subarray with same char, but here we can replace characters k times to get all same chars in that substring*/

// Sliding Window Approach
/* We use an hashmap for this we count the fre of highest occuring elements and also other elements
if the (highest freq element - others)==k then what substring is valid as other elements are equal to amount of k i.e replacements*/

// T.C -> O(n)
// S.C -> 0(1)

int mxm(vector<int> &a)
{
    int m = 0;
    for (int i = 0; i < 256; i++)
    {
        m = max(m, a[i]);
    }
    return m;
}
int characterReplacement(string s, int k)
{
    vector<int> freq(256, 0);
    // freq array to hold frequency of letters

    int low = 0; // low ptr
    int res = 0; // size will be never be 0

    for (int high = 0; high < s.size(); high++)
    {
        freq[s[high]]++;
        int len = high - low + 1;
        // calculate the current len

        int maxm = mxm(freq);
        // find element with highest frequency in this effective length

        int diff = len - maxm;
        // lets see if the current substring has exact k elements to replace
        while (diff > k)
        {
            freq[s[low]]--;
            low++;
            maxm = mxm(freq);
            len = high - low + 1;
            diff = len - maxm;
        }

        res = max(len, res);
    }

    return res;
}

int main()
{

    return 0;
}