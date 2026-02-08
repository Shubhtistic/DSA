#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// Problem Statement
/*Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.*/

// Sliding window pattern
/*in this what we can do is we can maintain a hashmap and when the map exceeds the current subarray (window size)
then we just remove the starting elements in oder to try to remove duplicates
as Hashmap stores the frequency of each element so if the size of current window is more than current winndow size
it means that the hashmap contains multiple for some given element
Until the k==map.size() we can say that k (window length) has no duplicates if it had duplicates map.size < k */

// T.C -> O(n)
// S.C -> O(1)

int lengthOfLongestSubstring(string s)
{

    unordered_map<char, int> mp;
    int low = 0;
    int hg = 0;
    for (int high = 0; high < s.size(); high++)
    {
        mp[s[high]]++;
        int k = (high - low + 1);

        while (mp.size() < k)
        {
            mp[s[low]]--;
            if (mp[s[low]] == 0)
            {
                mp.erase(s[low]);
            }
            low++;
            k = high - low + 1;
            // Very imp, Dont forget to uodate for new size
        }

        if (mp.size() == k)
        {
            hg = max(hg, k);
        }
    }

    return hg;
}

int main()
{

    return 0;
}