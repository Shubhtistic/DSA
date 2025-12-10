#include <algorithm> // for sort
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.
// The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

// lets try using an map, the map will simply store all the elements from array 1 and 2 with counts
// we dont have anything to do with counts(vlaues) we just want the keys(elements)
// T.C -> O(n+m) n -> length of first array , m -> length of second array
// S.c -> o(k+k) -> O(2k) => O(k), distinct elements k -> (0 ≤ k ≤ min(n, m))

vector<int> unionArray_map(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    for (auto item : nums1)
    {
        mp[item]++;
    }
    for (auto item : nums2)
    {
        mp[item]++;
    }
    vector<int> op;
    for (auto [key, value] : mp)
    {
        op.push_back(key);
    }
    return op;
}

// lets try using an set which will be slighly better as it will store the counts, which we dont even need anyway
// Time: O(n + m + k log k) (hash insertions + sorting)
// Space: O(k) (set + output vector)
vector<int> unionArray_set(const vector<int> &nums1, const vector<int> &nums2)
{
    unordered_set<int> s;

    // Step 1: Insert all elements from both arrays
    for (int x : nums1)
        s.insert(x);
    for (int x : nums2)
        s.insert(x);

    // Step 2: Convert set to vector
    vector<int> result(s.begin(), s.end());

    // Step 3: Sort the vector to maintain ascending order
    sort(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 44, 4, 4, 5};
    vector<int> nums2 = {2, 3, 5, 6, 7, 8};

    vector<int> unionArr = unionArray_set(nums1, nums2);
    for (int x : unionArr)
        cout << x << " ";
    cout << endl;

    return 0;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 44, 4, 4, 5};
    vector<int> nums2 = {2, 3, 5, 6, 7, 8};
    for (auto item : unionArray_map(nums1, nums2))
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto item : unionArray_set(nums1, nums2))
    {
        cout << item << " ";
    }
    return 0;
}
