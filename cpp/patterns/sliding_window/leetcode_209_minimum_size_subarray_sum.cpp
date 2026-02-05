#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Problem Statement
/*Given an array of positive integers nums and a positive integer target,
 return the minimal length of a subarray whose sum is greater than or equal to target.
 If there is no such subarray, return 0 instead.
*/

// Sliding Window Approach
/*We are looking for an subarray, and we need a dynamic sliding window
So what we can do start the low and high ptrs from the start and keep expanding the window until subarray sum >= target
after this we shift low ahead to see if we can more smaller length subarray and we repeat this until end*/

// T.C -> O(n)
// S.C -> O(1)

int minSubArrayLen(int target, vector<int> &nums)
{
    int low = 0;
    int sum = 0;
    int ml = INT_MAX;

    for (int high = 0; high < nums.size(); high++)
    {
        sum = sum + nums[high]; // we keep increasing window until we find out the condition

        while (sum >= target)
        {
            ml = min(ml, high - low + 1);
            sum = sum - nums[low]; // remove last sum and reduce window further
            low++;
        }
    }

    if (ml == INT_MAX)
    {
        return 0;
    }

    return ml;
}

int main()
{
    vector<int> nums = {2, 3, 4, 5, 7, 8, 9};

    cout << minSubArrayLen(5, nums) << endl;
    return 0;
}