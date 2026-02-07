#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// Problem Statement
/*You are given a string s consisting only lowercase alphabets and an integer k.
Your task is to find the length of the longest substring that contains exactly k distinct characters.
Note : If no such substring exists, return -1.

Examples:
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.*/

// Sliding Window Approach
/*What we can do is start both low and high at index 0 as this is an dynamic window question
We can use a map to store frequency of chars and once the size of map is equal to k that means
We found a substring which contains k distint characters (by size i mean no of key - value pairs)
After that we keep iterating and once we exceed size more than k we try to remove elements from last and also decrease their frequency
as we decrease frequncy at some point any characters count will be zero so we delete that char and then our
window and can again grow and add one more character as we removed one and after again we map.size == k we check length of that substring*/

int longestKSubstr(string &s, int k)
{
    // code here
    int res = INT_MIN;
    int low = 0;
    unordered_map<char, int> freq;

    for (int high = 0; high < s.size(); high++)
    {
        freq[s[high]]++;

        while (freq.size() > k)
        {
            freq[s[low]]--;
            if (freq[s[low]] == 0)
            {
                freq.erase(s[low]);
            }
            low++;
        }

        if (freq.size() == k)
        {
            res = max(high - low + 1, res);
        }
    }

    if (res == INT_MIN)
    {
        return -1;
    }
    return res;
}

int main()
{

    return 0;
}