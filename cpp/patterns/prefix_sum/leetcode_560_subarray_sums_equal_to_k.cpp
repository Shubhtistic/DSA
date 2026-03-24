#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem Statement
/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/

// Brute Force Approach
/*The classic brute force for any subarray question is nested loops.
Generate all possible subarrays and check the condition.
We keep adding elements and check if the sum becomes k*/

// T.C -> O(n^2)
// S.C -> O(1)

int subarraySum_brute(vector<int> &nums, int k)
{
    int c = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                c++;
            }
        }
    }
    return c;
}

// Optimal Approach
/*This took me almost a full day to grasp, so explaining in simple way.

In brute force we were checking all (i,j) and calculating sum again and again.

Now using prefix sum idea:
Instead of recalculating sums, we store cumulative sum till current index.

Let prefix sum till current index be 'x'.
Now we want a subarray with sum = k.

So think like this:
If current total is x, then we need some previous part which is (x - k).

Because:
x - (x - k) = k

So if a prefix sum of (x - k) already existed before,
then removing that part gives us a subarray of sum k.

So at every index:
we check how many times (prefix - k) has appeared before.

If it appeared 2 times → we have 2 subarrays ending here.

So hashmap stores:
prefix sum → how many times it occurred

Also:
mp[0] = 1 means:
sum from start itself can be k (very important edge case)
*/

// T.C -> O(n)
// S.C -> O(n)

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1; // handles subarrays starting from index 0

    int prefix = 0, cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        prefix = prefix + nums[i];

        // we want sum k, so check if (prefix - k) existed before
        // if yes, then removing that part gives subarray sum = k
        int remove = prefix - k;

        cnt = cnt + mp[remove];
        // how many times that prefix appeared → that many subarrays

        mp[prefix]++;
        // store current prefix for future
    }
    return cnt;
}

int main()
{

    return 0;
}