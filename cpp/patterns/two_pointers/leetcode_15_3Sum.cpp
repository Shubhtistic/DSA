#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

// Problem Statement
/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.*/

// Two Pointer Approach
/*What we can do is , sort the array so its in order(reason exaplained below) after that we fix one pointer and move over the remaining array
so it becomes one stationary pointer + two pointer pattern , by this way we find triplets by keeping one pointer at fixed position and
finding triplets from the remaining array using two pointers
Reason for Sorting: Once we sort the array all elements will be in order so we can easily skip duplicates so no triplets are repeated*/

// T.C -> O(n^2)
// S.C -> O(1)

// Another Two Pointer Approach
/*instead of handling duploicates manually we can use an set data structure to store all unique elements
this would make hanlding duplicates very easy, But would require O(n) extra Space And remaining logic would be as it is.
But we will stick with the O(1) solution*/

void two_sum_helper(int f, vector<int> &nums, vector<vector<int>> &abc)
{
    int i = f + 1; //  always after fixed ptr 'f'
    int j = nums.size() - 1;
    while (i < j)
    {
        int sum = nums[i] + nums[j] + nums[f];
        if (sum > 0)
        {
            j--;
            // sum is bigger so reduce last elements
            /*this also handles duplicates as if number is repeated sum will be still same so pointer again shifts*/
        }
        else if (sum < 0)
        {
            i++;
            // sum is small, move ahead to get more +ve numbers
            /*this also handles duplicates as if number is repeated sum will be still same so pointer again shifts*/
        }

        else
        {
            // found a triplet
            abc.push_back({nums[f], nums[i], nums[j]});
            i++;
            j--;
            while (i < j && nums[i] == nums[i - 1])
            {
                // duplicate found
                i++;
            }
            while (i < j && nums[j] == nums[j + 1])
            {
                // duplicate found
                j--;
            }
        }
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> abc;
    sort(nums.begin(), nums.end()); // O(n*logn)

    for (int f = 0; f < nums.size(); f++)
    {

        if (nums[f] > 0)
        {
            // first number turned out to be +ve
            // all triplets will be bigger than 0
            break;
        }

        if (f != 0 && nums[f] == nums[f - 1])
        {
            continue;
        }
        else
        {
            two_sum_helper(f, nums, abc);
        }
    }

    return abc;
}

int main()
{
    vector<int> test = {-1, 0, 1, 2, -1, -4};
    auto abc = threeSum(test);

    for (auto a : abc)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
    }

    return 0;
}