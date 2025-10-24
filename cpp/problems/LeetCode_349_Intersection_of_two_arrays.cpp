#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Simple brute force approach
// simply use two loops
// first loop keeps track of first array
// second array compares the element of first array to all elements of second array
// if elements are same we just add it to the output vector
// T.C -> O(n x m) n -> length of first array , m -> length of second array
// S.C -> Let k = number of distinct elements in the intersection (0 ≤ k ≤ min(n, m))
// S.C -> O(k+k) -> O(2k) -> O(k)

vector<int> brute_force(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> op;
    unordered_set<int> st;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                st.insert(nums1[i]);
                continue;
            }
        }
    }
    for (auto item : st)
    {
        op.push_back(item);
    }
    return op;
}

// Lets try to optimize it a bit
// what we can do is make an hashmap so the stores the element as non-duplicate keys
// and then we can make an set for the second array so we dont search for element twize in hash map if second array has duplicates
// then we simply find function to see if both have common elements
// append those common elements to the output list
// Note: Use unordered set and map as they provide 0(1) element lookup in find() function
// T.C -> O(n+m) n -> length of first array , m -> length of second array
// S.C -> map -> O(n) worst case , set -> O(m) .. worst case and o/p vector k distinct elements k -> (0 ≤ k ≤ min(n, m))
// S.c -> O(n+m+k) .. in worst case k can be equal to either n or m or both if they are of equal length
// lets assume k=n
// S.C -> O(n+m)

vector<int> better_approach(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    for (auto item : nums1)
    {
        mp[item]++;
    }
    unordered_set<int> st;
    for (auto item : nums2)
    {
        st.insert(item);
    }
    vector<int> op;
    for (auto item : st)
    {
        if (mp.find(item) != mp.end())
        {
            op.push_back(item);
        }
    }
    return op;
}

// Lets try an optimal solution to the question
// we can use some tweaks to save space
// for example always use the smaller array to make an set
// then we compare that set with second array and store the same elemnts in another set to avoid duplicates
// then simply populate vector with second set havinf all intersected elements
// T.C -> O( n+m+k) -> O(n+m)
// S.c -> O( min(n,m) + k)
vector<int> optimal(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
    {
        swap(nums1, nums2);
        // nums1 is now smaller
        // swap function simply swaps the two vector
    }
    // store elements of smaller array in a set
    unordered_set<int> st;
    for (auto item : nums1)
    {
        st.insert(item);
    }
    unordered_set<int> int_st;
    for(auto item:nums2){
        if(st.find(item)!=st.end()){
            int_st.insert(item);
        }
    }
    vector<int> op(int_st.begin(),int_st.end());
    return op;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (auto item : brute_force(nums1, nums2))
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto item : better_approach(nums1, nums2))
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto item : optimal(nums1, nums2))
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}