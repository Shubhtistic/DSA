#include <iostream>
#include <vector>
using namespace std;

// Problem Statement
/*Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
*/

// Brute Force Approach
/*Use two nested loops to calculate all possible subarrays and check all subarray product less than k*/

// T.C -> O(n^2)
// S.C -> O(1)

int numSubarrayProductLessThanK_brute(vector<int> &nums, int k)
{
    int c = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        long long int p = 1;
        // to avoid overflow
        for (int j = i; j < nums.size(); j++)
        {
            p = p * nums[j];
            if (p < k)
            {
                c++;
            }
            else
            { // break as product > k
                // all subarray after this be invalid, as product>k already
                // also avoids overflow
                break;
            }
        }
    }
    return c;
}

// OPTIMAL Approach -> Sliding Window
/*If we take a look at the question 1) find the subarray count, 2)less than k
We can utilize the sliding window method to solve this, what we can do is start both high low at index 0
and we keep increasing the window size until product<k, if product exceeds k we remove low elements and shrink window
we do this until the last index and we get all valid subarrays*/

// T.C-> O(n)
// S.C-> O(1)
int numSubarrayProductLessThanK_optimal(vector<int> &nums, int k)
{
    long long int product = 1;
    int c = 0;

    int low = 0;

    for (int high = 0; high < nums.size(); high++)
    {
        product = product * nums[high];

        // low <= high most imp edge case as low may cross high
        // example what if product becomes to k, then this will get stuk in a loop
        // and low may go out of bounds
        while (product >= k and low <= high)
        {
            product = product / nums[low];
            low++;
        }

        if (product < k)
        {
            c = c + (high - low + 1);
        }
    }
    return c;
}

int main()
{

    return 0;
}