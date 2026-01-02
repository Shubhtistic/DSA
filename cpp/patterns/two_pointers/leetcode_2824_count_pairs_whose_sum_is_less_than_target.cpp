#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement
/*Given a 0-indexed integer array nums of length n and an integer target,
return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

Example 1:
Input: nums = [-1,1,2,3,1], target = 2
Output: 3
Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
- (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target
- (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target. */

// Brute Force Approach
/* We can simply use two loops, to iterate over the array and test all possible pairs
 */
// T.C -> O(n^2)
// S.C -> O(1)

int brute_force(vector<int> &nums, int target)
{
    int c = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) < target)
            {
                c++;
            }
        }
    }
    return c;
}

// Optimal Approach
/* Now the optimal solution is not straighforward and we may need some time to wrap our head around logic.
what we will do is, we will use an special property of sorting i.e once the data is sorted, we will have extremes
extremes -> lowest nums first and largest number at last index.
so we will compare the extremes and if the sum of extremes is less than target then all the pairs between that range will be valid.
We will use pointers i and j, where i starts at index 0 and j at last index ( extremes )
Dry Run Example:->
Nums1= [-1,1,2,3,1] -> After Sorting -> Nums1=[-1,1,1,2,3]

1st iteration:
nums[0] + nums[4] (extremes) = 2 .. not smaller than , we now reduce pointer j to index[3]

2nd Iteration:
nums[0] + nums[3] (new extremes) = 1 .. smaller than , all pairs between these range are valid.
Count= count+ (j-i) .. to count all pairs present between that range
we now increment pointer i

3rd Iteration:
nums[1] + nums[3] (new extremes ) = 3 .. not smaller than , reduce j pointer to index[2]

4th iteration:
nums[1]+nums[2] (new extremes ) = 2 .. not smaller than , reduce j pointer to index[1]

5th iteratioN:
nums[1]+nums[1] -> not possible to form a pair as both extremes are at same place.
Exit the Loop.

Final Count = 3
*/

// T.C -> O(nlogn) .. Sorting Dominates Over while loop O(n)
// S.C -> O(1)

int optimal(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end()); // O(nlogn)
    int i = 0;
    int j = nums.size() - 1;
    int count = 0;

    while (j > i) // O(n)
    {

        if (nums[i] + nums[j] >= target)
        {
            j--;
            continue;
        }
        else
        {
            if (nums[i] + nums[j] < target)
            {

                count = count + (j - i);
                i++;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> examples = {1, 2, -3, -4, 8, 9, 0};
    int target = 4;

    auto ans1 = brute_force(examples, 4);
    auto ans2 = optimal(examples, 4);

    cout << ans1 << " " << ans2 << " ";

    return 0;
}