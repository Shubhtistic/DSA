#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem Statement
// You are given an array of numbers.
// You need to find the k elements that appear most frequently in the array.
// Return these elements in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Explanation:
// 1 appears 3 times
// 2 appears 2 times
// 3 appears 1 time
// The top 2 frequent elements are 1 and 2

// Example 2 (tie case): -> imp
// Input: nums = [1,1,2,2,3,3], k = 2
// Output: [1,2,3]
// Explanation:
// All three numbers have the same frequency (2 times).
// Since they tie with the k-th frequency, we return all of them.

// Solution
// To be honest I tried many approaches by myself, also a brute force.
// But the brute force was also failing in some test cases.
// So the only approach and most probably the optimal approach is bucket sort.
// What a bucket sort simply is — each index has the elements that have counts equal to its index.
// For example, let’s assume number '1' appears 4 times in an array.
// So number '1' will be at index 4 of the bucket array.
// So first we make a hash map to store numbers with their frequency, and each index of the bucket array is a list.
// So it can have multiple elements of the same count.
// For example [1,1,1,3,3,5,4,4]
// Map looks something like {1:3 , 3:2 , 5:1, 4:2}
// So the bucket array will look something like bucket=[0, [5], [3,4], [1]]
// So the last k indexes will be k most frequent elements.
// Example k=2 so the 2 most frequent elements are [3,4] and [1].
// S.C -> O(n)
// T.C -> O(n)

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    // Count frequency
    for (int num : nums)
    {
        if (freq.find(num) != freq.end())
        {
            freq[num] += 1;
        }
        else
        {
            freq[num] = 1;
        }
    }

    vector<vector<int>> bucket(nums.size() + 1); // 1-based count in bucket list
    // Syntax to create 'n' empty lists inside a list
    for (auto &pair : freq)
    {
        int num = pair.first;
        int count = pair.second;
        bucket[count].push_back(num);
    }

    // Collect top k frequent from high count to low
    vector<int> res;
    int l = 0;
    for (int i = nums.size(); i > 0; i--)
    {
        if (!bucket[i].empty())
        {
            for (int val : bucket[i])
                res.push_back(val); // Directly dump all elements of same frequency
        }
        l++;
        // Even though it’s a nested loop,
        // the total number of operations across both loops is O(n), not O(n²).
        // This is because there’s no repeated scanning of the same data —
        // every element contributes once to exactly one bucket[i]
        if (l == k)
        {
            return res;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3};
    vector<int> ans = topKFrequent(nums, 2);
    for (int x : ans)
        cout << x << " ";
    return 0;
}
