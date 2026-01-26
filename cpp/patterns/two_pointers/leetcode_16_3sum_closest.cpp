#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Problem Statement
/*Given an integer array nums of length n and an integer target,
find three integers at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

// Two/Three Pointer Approach
/*We can solve it just like we did for normal three sum question, i.e
fix one pointer and then use two pointer approach on remaining array and we also need to sort just like we did in 3sum and 2sum.
We maintain a min diff so if any new sum appears which is closer than already present then we get new closest sum
*/

// T.C -> O(n^2)
// S.C -> O(1)

int threeSumClosest(vector<int> &nums, int target)
{

    sort(nums.begin(), nums.end()); // O(nlogn)
    int res_sum = nums[0] + nums[1] + nums[2];

    int min_diff = INT_MAX;

    // fixed element
    for (int fixed = 0; fixed < nums.size() - 2; fixed++)
    {
        int start = fixed + 1;
        int end = nums.size() - 1;
        // start end here
        // so everytime we have proper ending length

        while (start < end)
        {
            int new_sum = nums[fixed] + nums[start] + nums[end];

            if (new_sum == target)
            {
                return new_sum;
            }
            else if (new_sum > target)
            {
                end--;
            }
            else
            {
                start++;
            }

            int new_diff = abs(new_sum - target);
            // calculates new diff b/w the sum
            if (new_diff < min_diff)
            {
                res_sum = new_sum;
                min_diff = new_diff;
            }
        }
    }

    return res_sum;
}

int main()
{
    vector<int> test = {-1, 2, 1, -4};
    cout << threeSumClosest(test, 1) << endl;
    return 0;
}