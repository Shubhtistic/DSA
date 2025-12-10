#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// question description
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// brute force
// ## brute force method
// run two loops to check indexes
// T.C -> O(n^2)
// S.C O(1)

vector<int> brute_method(const vector<int> &nums, int t)
{
    vector<int> idx;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == t)
            {
                idx.push_back(i);
                idx.push_back(j);
            }
        }
    }
    return idx;
}

// lets try an hashmap method
// we simply do like for example 8 + _ =14 so we just find if the 14-8 elements is present in hashmap(diict in python)
// T.C -> O(n)(in c++ maps -> O(nlogn) & unordered_sets -> O(n))
// S.C -> O(n)


vector<int> optimal_method(const vector<int> &nums, int t)
{
    vector<int> idx;
    unordered_map<int,int> mapp;
    for(int i=0;i<nums.size();i++){
        mapp[nums[i]]=i;

    }
    for(int i=0;i<nums.size();i++){
        int c=t-nums[i];
        if(mapp.find(c)!=mapp.end()){
            idx.push_back(i);
            idx.push_back(mapp[c]);
            break;
        }

    }
    return idx;
}

int main()
{
    vector<int> nums = {11, 7, 2, 15};
    int target = 9;
    for (auto item : brute_method(nums, target))
    {
        cout << item << " ";
    }
    cout << "\n";
    for (auto item : optimal_method(nums, target))
    {
        cout << item << " ";
    }

    return 0;
}