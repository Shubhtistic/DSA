#include <iostream>
#include <vector>
#include <unordered_set>
#include<map>
using namespace std;

// this question aks to return true if one element is present more than once
// otherwise return false

// first lets try using an brute force to get some idea
// Use two loops to just iterate over the vector, take one index at a time and compare to all
// we cancel out one index at a time if its unique so we dont iterate over it again
// this function works but will give TLE
// T.C -> O(n^2)
// S.C -> O(1)
bool brute_force(const vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            // no need for j=0 as the previus i is compared with all indices
            if (nums[i] == nums[j])
            {
                return true;
                // this simply does
                // lets say nums=[2,3,4,5]
                // on first iteration nums[0]=2
                // enter second loop and does
                // is 2==3 , is 2==4 , is 2==5
                // follow this for all iteration
            }
        }
    }

    return false;
}

// we have an another method we can directly use an unordered set of C++ STL
// insert all the all values of array into the set as the does not allow duplicate entries
// is both have same size it means all elements are distinct
// T.C -> O(n)
// S.C -> O(n)
bool using_set_betterANDoptimal(const vector<int> &nums)
{ // better or optimal solution
    unordered_set<int> my_set;

    // i have an g++17 so contains() method doesnt work on my device
    // for (auto temp : nums)
    // {
    //     if (my_set.contains(temp))
    //     {
    //         return true;
    //     }
    //     my_set.insert(temp);
    // }

    for (auto temp : nums)
    {
        my_set.insert(temp);
    }
    if (my_set.size() == nums.size())
    {
        return false;
    }
    return true;
}


bool using_map_betterANDoptimal(const vector<int> &nums)
{ // better or optimal solution
    map <int,int> my_map;

   

    for (auto temp : nums)
    {
        my_map[temp]+=1;
        if(my_map[temp]>1){
            return true;
        }
    }

    return false;
}

// another better or kind of optimal approch is using an hashmap counter 
// simple store elements with their and if any element is greater than 1 return true
int main()
{
    vector<int> nums = {2, 3, 4, 5, 6, 7, 7, 8};
    if (brute_force(nums))
    {
        cout << "Contains Duplicates\n";
    }
    if (using_set_betterANDoptimal(nums))
    {
        cout << "Contains Duplicates\n";
    }

    if (using_map_betterANDoptimal(nums)){
        cout << "Contains Duplicates\n";
        
    }
    return 0;
}
