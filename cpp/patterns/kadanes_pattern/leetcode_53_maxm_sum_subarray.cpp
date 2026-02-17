#include <iostream>
#include <vector>
using namespace std;

// Problem Statement
/*Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
*/

// What the question states
/*we have to return a contiguous subarray that has the highest sum*/

// Brute force approach
/*Use two loops to build all possible subarray and find maxm sum*/
// T.C -> O(n^2)
// S.C -> O(1)

int maxSubArray_brute(vector<int> &nums)
{
    int mx = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            mx = max(mx, sum);
        }
    }
    return mx;
}

// Optimal Solution -> kadanes pattern
/*We can solve this question using the kadanes pattern, acc to kadanes pattern we traverse the array from start to end
continuously building values or sum and we best maintan a best_ending i.e best result we have got till far (in this case sum)
and then acc to this pattern for every index 'i' we have two options. 1 -> merge that value with best_ending or start a new best_ending
we will see how to do this code
After following this 2-3 simple steps we can solve this question*/
// T.C -> O(n)
// S.C -> O(1)

int maxSubArray_optimal(vector<int> &nums)
{
    // start at zero as we have no previous info to begin with
    int best_ending = nums[0]; // assumed this is best ending, can be right or wrong -> just a assumption
    int max_sum = nums[0];     // also assumed

    for (int i = 1; i < nums.size(); i++)
    {
        int v1 = best_ending + nums[i];
        // this can either decrease our best ending or increase it

        int v2 = nums[i];
        // what if a new index has higher value than our best_ending
        // start a new best_ending with that
        best_ending = max(v1, v2); // new best ending
        max_sum = max(max_sum, best_ending);
    }
    return max_sum;
}

int main()
{

    return 0;
}