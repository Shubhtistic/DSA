#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

// Problem statement
/*Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

// Brute Force Approach
/* Using two loops to build all possible subarrays and find out highest product*/
// T.C --> O(n^2)
// S.C --> O(1)

int maxProduct_brute(vector<int> &nums)
{
    int mp = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        int p = 1;
        for (int j = i; j < nums.size(); j++)
        {
            p = p * nums[j];
            mp = max(p, mp);
        }
    }

    return mp;
}

// Optimal Approach -> kadanes pattern
/*As we know according to kadanes pattern as we have an best_ending i.e best previous value we had
for every index i we have two options we can inrease our best_endding or that index 'i' starts a new best_ending
so if you the question maxm subarray sum (leetcode 53) we have solved it take a look in repo
this question is kind of similar to it, but you replicate that logic the main issue we will face is handling negatives
for example the array, nums=[-1,2,-3] if you go by normal logic then 2 is largest but if you look closely -1x2x-3=6 which is the largest
So the trick is to work around this we need to add just a bit of tiny thing, we also track a min product.
what maintaning a min product does is in case a number is negative once it encounters another negative the value suddenly becomes +ve
and that new +ve value may be biggest subarray product.*/

// T.C -> O(n)
// S.C -> O(1)

int maxProduct_optimal(vector<int> &nums)
{ // assume and initialize everything at index 0 -> just as normal for every question
    int mx = nums[0];
    int mn = nums[0];
    int res = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int v1 = nums[i];      // the current element may be highest
        int v2 = mn * nums[i]; // maybe a negative, makes product -ve or if already -ve then another -ve -> big +ve number
        int v3 = mx * nums[i]; // new max

        mx = max({v1, v2, v3});
        mn = min({v1, v2, v3});
        res = max({res, mn, mx});
    }

    return res;
}

int main()
{

    return 0;
}