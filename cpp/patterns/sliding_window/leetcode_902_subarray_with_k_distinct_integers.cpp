#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Problem Statement
/*Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

// Brute Force Approach
/*For an subarray to find counts the best thing we can do is just use two loops.
the inner loop builds the subarray and we use an hashmap to see for that specific subarray does it contain k exact integers
if it exceeds k distinct integers we can easily break from that iteration as we cant find anymore distinct ints in that array
we use a hashmap because the size of hashmap tells us how many elements we have so we will store elements and keys and their counts as values*/

// T.C -> O(n^2)
// S.C -> O(n)

int subarraysWithKDistinct_brute(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i; j < nums.size(); j++)
        {
            mp[nums[j]]++;

            if (mp.size() == k)
            {
                count++;
            }
            if (mp.size() > k)
            {
                break;
            }
        }
        mp.clear();
    }

    return count;
}

// Optimal Approach -> Sliding Window with HashMap
/*
Since the problem asks to count subarrays with exactly K distinct integers,
and subarray means a continuous segment, we should think about the sliding window technique.

Directly counting "exactly K" is tricky in a single window.
So we use a standard transformation:

Exactly K = AtMost(K) - AtMost(K - 1)

We first build a helper function that counts subarrays with at most K distinct elements.
In a valid window (distinct <= K), the number of valid subarrays ending at 'high'
is (high - low + 1).

By subtracting AtMost(K - 1) from AtMost(K), we remove all subarrays
that have fewer than K distinct elements, leaving only those with exactly K.
*/

// T.C -> O(n)
// S.C -> O(n)

int atMostK(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;

    unordered_map<int, int> mp;
    int low = 0;
    int count = 0;

    for (int high = 0; high < nums.size(); high++)
    {
        mp[nums[high]]++;

        while (mp.size() > k)
        {
            mp[nums[low]]--;
            if (mp[nums[low]] == 0)
                mp.erase(nums[low]);
            low++;
        }

        count += (high - low + 1);
    }

    return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main()
{

    return 0;
}