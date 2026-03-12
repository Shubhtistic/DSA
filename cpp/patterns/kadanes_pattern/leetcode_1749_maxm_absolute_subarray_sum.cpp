#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Problem statement
/*
You are given an integer array nums.
The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:
If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.


Example 1:
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
*/

// Brute Force Approach
/* We can use the nested loops method to generate all possible subarrays and from all possible sums (-ve and +ve)
we will find the largest one.
Imp Note: we find the absolute sum and not the absolute values of elements. Find the sum normally and take the absolute of that sum.*/

// T.C -> O(n^2)
// S.C -> O(1)

int maxAbsoluteSum_brute(vector<int> &nums)
{
    int max_sum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            max_sum = max(max_sum, abs(sum));
            // compare every possible sum
        }
    }

    return max_sum;
}

// Optimal Approach -> Kadane's min sum + Kadane's max sum
/* The question asks to find a sum whose absolute value is the largest. This does not affect +ve sums as they are already absolute.
The biggest magic happens when a sum is -ve and when we take the absolute it becomes +ve.
So the subarray has a -ve sum which is very small and when we take absolute it becomes a big +ve sum.

Example:
[-1,3,4,2,-6,-9]

So from the array we can see the biggest +ve sum is 9 [3,4,2]
and the smallest -ve sum is -15 [-6,-9]

And the magic happens when we take the absolute of both or only the smaller value
abs(-15)= 15
way bigger than 9 and it becomes the largest absolute sum.

And in a different scenario if the +ve sum was still bigger than abs(-ve sum) then that +ve would simply be the biggest absolute sum.

So if you haven't caught up till now, we are simply using Kadane's min sum and max sum together
and at the end the largest absolute value from either min or max sum.*/

// T.C -> O(n)
// S.C -> O(1)

int maxAbsoluteSum_optimal(vector<int> &nums)
{
    int global_max = nums[0];
    int global_min = nums[0];

    int current_max = nums[0];
    int current_min = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int v1 = current_max + nums[i]; // lets see if current max goes up
        int v2 = current_min + nums[i]; // lets see if current min goes down
        int v3 = nums[i];               // maybe this element starts new min or max sum

        current_max = max({v1, v2, v3});
        current_min = min({v1, v2, v3});

        // global update
        global_max = max(global_max, current_max);
        global_min = min(global_min, current_min);
    }
    return max(global_max, abs(global_min));
}

int main()
{

    return 0;
}
