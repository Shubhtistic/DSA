

#include <iostream>
#include <vector>
using namespace std;

// In this question wee are tolld to move all te zeros to the end of te array and
// also preserve order of non zero elements

// Brute force approach
// T.C & S.C -> O(n)
// we simply just make two vectors one containing and other one of non_zeros
// at the end simply add them and either assign it to original or just return it

vector<int> brute_method(const vector<int> &nums)
{
    vector<int> non_zeros;
    vector<int> zeros;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            non_zeros.push_back(nums[i]);
        }
        else
        {
            zeros.push_back(nums[i]);
        }
    }

    for (int value : zeros)
    {
        non_zeros.push_back(value);
    }
    // for each wont run for empty vector, no need to worry

    return non_zeros;
    // or
    // nums=non_zeros;
    // we have to remove const for this
    // return nums;
}

// two pointer approch
// simply first fill the vector with the non zero elements and then
// start from counter variable and fill with zeros
// T.C -> O(n)
// S.C -> O(1)
vector<int> optimal(vector<int> nums)
{

    int counter = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            nums[counter] = nums[i];
            counter++;
            // we just ignore zeros
        }
    }
    if (counter != 0)
    {
        for (int i = counter; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {0, 0, 0, 0, 12};
    cout << "With brute force \n";
    for (auto item : brute_method(nums))
    {
        cout << item << " ";
    }

    cout << "With Optimal Approch \n";
    for (auto item : optimal(nums))
    {
        cout << item << " ";
    }

    return 0;
}