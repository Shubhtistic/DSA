#include <iostream>
#include <vector>
using namespace std;

// this question can be termned as an easy version of leetcode 75 -> sort colours
// Problem statement
/*we will be given an array of 0s and 1s we have to sort them without using any library function */

// Straightforward easy approach
/* we can just count number of 0s and 1s and then just fill the array with that number of 0s and 1s*/

// T.C -> O(n)
// S.C -> O(1)

void easy_method(vector<int> &nums)
{
    int os = 0;
    int zs = 0;

    for (int i = 0; i < nums.size(); i++) // T.C -> O(n)
    {
        if (nums[i] == 0)
        {
            zs++;
        }
        else
        {
            os++;
        }
    }

    for (int i = 0; i < zs; i++)
    // T.C -> O(z) .. no of zeros
    // Worst Case -> O(n) .. if all elements are zeros
    {
        nums[i] = 0;
    }
    for (int i = zs; i < nums.size(); i++)
    // T.C -> O(ones) .. no of ones
    // Worst Case -> O(n) .. if all elements are ones
    {
        nums[i] = 1;
    }
}

// Actual Two Pointer Approach
/* With the two pointers that we have we can perform in place substitution
we can use two pointers at extreme ends, if an end element is already 1 then we shift back (decrease pointer)until we find zero and
same logic from front pointer and then we replace them. Lets try Coding it
*/

void sort_colours(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        if (nums[i] == 0)
        {
            i++;
        }
        else if (nums[j] == 1)
        {
            j--;
        }
        else
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
}
int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 1};
    vector<int> nums1 = {0, 1, 1, 1, 0, 0, 1, 1};
    easy_method(nums);
    sort_colours(nums1);
    cout << "nums" << endl;
    for (auto a : nums)
    {
        cout << a << " ";
    }
    cout << "nums1" << endl;
    for (auto a : nums1)
    {
        cout << a << " ";
    }
    return 0;
}