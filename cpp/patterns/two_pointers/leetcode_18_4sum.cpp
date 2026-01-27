#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem Statement
/*Given an array nums of n integers,
return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]*/

// Two/multi Pointer Approach
/*Please All question of three sum present in the repo this question is just an extension of classic 3sum
Just like Three sum we will use fixed Pointer and and the two sum pattern
we start at index first and then second loop follows element after that and so on
We sort the Array to skip duplicates and also move the pointers*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    if (nums.size() < 4)
    {
        return res;
    }

    for (int a = 0; a < nums.size() - 3; a++)
    // a atleast runs for a-> 0 so we get one element if all are duplicates
    {
        if (a > 0 and nums[a] == nums[a - 1])
        {
            continue;
        }

        for (int b = a + 1; b < nums.size() - 2; b++)
        {
            if (b > a + 1 and nums[b] == nums[b - 1])
            // Always check b>a+1 to check elememts of a and what are before b to skip duplicates
            //  it skips the first occurenect i.e a=0 b will start from 1 so  ->1>0+1 ... skipped for second element
            {
                continue;
            }

            int i = b + 1;
            int j = nums.size() - 1;

            while (i < j)
            {
                long long int sum = (long long)nums[a] + nums[b] + nums[i] + nums[j];
                // To Avoid Overflow
                // also typecast to long long so long long value can actually be stored

                if (sum == target)
                {
                    res.push_back({nums[a], nums[b], nums[i], nums[j]});
                    i++;
                    j--;

                    while (i < j && nums[i] == nums[i - 1]) // skip duplicates
                        i++;
                    while (i < j && nums[j] == nums[j + 1]) // skip duplicates
                        j--;
                }

                else if (sum > target)
                {
                    j--;
                }
                else if (sum < target)
                {
                    i++;
                }
            }
        }
    }
    return res;
}
int main()
{

    vector<int> np = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
    auto res = fourSum(np, 7);

    return 0;
}