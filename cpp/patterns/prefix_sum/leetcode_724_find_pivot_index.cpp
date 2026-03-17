#include <iostream>
#include <vector>
using namespace std;

/*Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal
to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array,
then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/

// What Question Asks to find out
/*Find a index such that the sum before that index (left side of index i) and sum after it (right side)
if they are both equal then that index is the pivot index.
if not then return -1*/

// ===================================================================================================================================

// Brute Force Appraoch
/*For brute Approch what we can do is we can run two loops as we always do
whenever we encounter a subarray question -> nested loops can help to find out the brute force appraoch first
we will find left sum (sum before the index i) and right sum (sum after index i)
IMP EDGE CASE :- Never count left_sum until the index i -> count just before index i and same for right_sum count after index i*/
// T.C -> O(n^2)
// S.C -> O(1)

int pivotIndex_brute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int left_sum = 0;
        int right_sum = 0;
        // build left sum
        // imp edge case
        // what if i=0 and also handles not including the index itself in left sum
        for (int j = 0; j < i; j++)
        {
            left_sum = left_sum + nums[j];
        }

        // build the right sum
        // start from i+1
        for (int j = i + 1; j < nums.size(); j++)
        {
            right_sum = right_sum + nums[j];
        }
        if (left_sum == right_sum)
        {
            return i;
        }
    }
    return -1;
}

// Prefix Sum Approach
/*If we look closely what the question asks, sum(left to i) == sum(right to i)
If we think a bit, its essentially like finding out sums on two sides of a index.
Hence we can use prefix sum over here to compute the sum already and then easily find left and right sums
Mathematical Reasoning:-
Left sum = prefix[i]  ... sum before i
right sum -> entire sum after prefix[i+1]
so we have to find right sum directly from the precalculated prefix array.
so we can try right sum = prefix[n]-prefix[i+1] ... from the entire prefix array sum, only take out slice of right sum
IN SHORT:-
prefix[i]==prefix[n]-prefix[i+1]*/

// T.C -> O(n)
// S.C -> o(n)

int pivotIndex_better(vector<int> &nums)
{
    vector<int> pf(nums.size() + 1, 0);

    // avoid mistake of using nums.size() as pf.size() always > nums.size()
    // using nums.size() skips last element of prefix sum i.e total sum of array
    for (int i = 1; i < pf.size(); i++)
    {
        pf[i] = pf[i - 1] + nums[i - 1];
    }
    int left_sum;
    int right_sum;
    for (int i = 0; i < pf.size() - 1; i++)
    {
        left_sum = pf[i];
        // sum before the current index i
        right_sum = pf[pf.size() - 1] - pf[i + 1];
        // subtract right from total to get right sum

        if (left_sum == right_sum)
        {
            return i;
        }
    }
    return -1;
}

// Best Optimal Way -> implicit prefix
/*Compared to the previous approach, we just need to reduce the space now. As we have already have liner time implementation
To reduce space, lets ask ourselves what was the main purpose of building the prefix array.
it was to have the total sum available to us so we can easily find our right sum and find left sum.
But if you think closely left sum could be easily found out as a running sum starting from index i.
so now the prefix array only has one function remaining, collect total sum to find our right sum.
Here comes the O(1) space solution.
If the main purpose of prefix remains only to store final sum why cant we use a normal variable to store it.
beacuse a normal variable would easily store the total sum in O(1) space, we dont even need the prefix array now.
We can have a normal running sum i.e left_sum and calculate right_sum from total sum
and then we can easily find out the pivot index in O(1) space*/

// T.C -> O(n)
// S.C -> O(1)

int pivotIndex_optimal(vector<int> &nums)
{
    int total = 0;
    for (int a : nums)
    {
        total += a;
    }

    int left_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // we do this first to avoid a edge case
        // what if right sum and left sum both are 0
        // and also what if index 0 is the pivot

        // get right_sum
        int right_sum = total - left_sum - nums[i];
        // remove nums[i] as we want sum after the index i

        if (left_sum == right_sum)
        {
            return i;
        }
        left_sum += nums[i];
    }

    return -1;
}

int main()
{

    return 0;
}