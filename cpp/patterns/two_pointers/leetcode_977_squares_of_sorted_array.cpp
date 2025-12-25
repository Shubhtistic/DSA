#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem statement
/*Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].*/

// brute force approach
// first square the array and then sort it
// T.C -> O(nlogn)
// S.C -> O(1)

vector<int> brute_force(vector<int> &nums)
{
    vector<int> nums2(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        nums2[i] = nums[i] * nums[i];
    }
    // o(n)

    sort(nums2.begin(), nums2.end());

    return nums2;
}

// time efficient approach
/* use two pointers, start and end. As the array is sorted in non-decreasing(ascending).
we use the two pointers to compare the absolute values one by one And
populate the return array directly with sqaure of that number*/

vector<int> optimal(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int k = nums.size() - 1;
    vector<int> res(nums.size());

    while (start <= end)
    {

        if (abs(nums[start]) > abs(nums[end]))
        {
            res[k] = nums[start] * nums[start];
            start++;
            k--;
        }
        else
        {
            res[k] = nums[end] * nums[end];
            k--;
            end--;
        }
    }
    return res;
}
int main()
{
    vector<int> nums1 = {-4, -3, 4, 7, 9};
    auto vec1 = brute_force(nums1);
    auto vec2 = optimal(nums1);

    for (auto item : vec1)
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto item : vec2)
    {
        cout << item << " ";
    }
    return 0;
}