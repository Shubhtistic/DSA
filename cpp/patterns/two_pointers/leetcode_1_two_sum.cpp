#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Problem Statement
/*Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]*/

// Brute force approach
/*We will use two loops to simply check for all possible sums and exit on first result */

// T.C -> O(n^2)
// S.C -> O(1)

vector<int> brute_force(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {}; // return empty vector
}

// Optimal Approach
/* In this approach we use an hash map to store the elements along with indices and use the elemets as keys, so we can easily return indices.
so in a single loop we check Complement = target - nums[i] and
then we check if that complement value is present in hashmap, if present we found the indices. */

// T.C -> O(n)
// S.C -> O(1)

vector<int> optimal(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end())
        {
            return {mp[complement], i};
        }
        mp.insert({nums[i], i});
        // insert does not update the key
        // so first occurence of number is always preserved
    }
    return {};
    // empty vector if we dont find anything
}
int main()
{
    vector<int> a = {2, 7, 11, 15};
    int target = 9;
    auto abc = optimal(a, target);
    for (auto a : abc)
    {
        cout << a<<" ";
    }
    return 0;
}