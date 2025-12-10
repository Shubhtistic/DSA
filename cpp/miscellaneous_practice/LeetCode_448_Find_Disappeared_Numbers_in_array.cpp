#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

// in thi we are given an array which has elements anywhere from 1 to n
// it will never have an element greater than n
// example:-
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

// we have to find which numbers are missing from the 1 to n range from the arayy

// easy approach
// we can make an set or or map set store all uniques and map does not allow duplicate keys
// we should use an ordered map as it has o(n) for lookup while map has
// and same for map also we will use an unordered map
// T.C -> O(n)
// S.C -> O(n) ... for map or set

vector<int> easy_using_map(const vector<int> &nums)
{
    unordered_map<int, int> my_map;
    vector<int> d;
    for (auto item : nums)
    {
        my_map[item]++;
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (my_map.find(i) == my_map.end())
        {
            d.push_back(i);
        }
    }

    return d;
}

vector<int> easy_using_set(const vector<int> &nums)
{

    unordered_set<int> my_set;

    vector<int> d;
    for (auto item : nums)
    {
        my_set.insert(item);
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if (my_set.find(i) == my_set.end())
        {
            d.push_back(i);
        }
    }

    return d;
}

// lets try optimizing it
//  we can use the array as it own presence
//  as we know the elements will not conatain any elements higher than 'n'
//  we can simple use it numbers to mark the indexes if any index remain unmarked it means that index is missing ultimately number is missing
//  as we know index start from 0 and numbers 1 from we only have to take that in consideration so we return i+1 for every missing index
//  T.C -> O(n)
//  S.C -> O(1)

/*

“We can optimize the space to O(1) by using the input array itself as a presence map.
Since numbers are in 1 ... n, each number can mark its corresponding index.
 After marking, the indices that remain unmarked correspond to missing numbers.”

*/

vector<int> optimal_method(vector<int> nums)
{
    vector<int> miss;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0)
        {
            nums[index] *= -1;
        }
        else
        {
            continue;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            miss.push_back(i + 1);
        }
    }
    return miss;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    for (auto item : easy_using_map(nums))
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto item : easy_using_set(nums))
    {
        cout << item << " ";
    }
    cout << endl;
    for (auto item : optimal_method(nums))
    {
        cout << item << " ";
    }

    return 0;
}