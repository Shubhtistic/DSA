#include <iostream>
#include <vector>
using namespace std;

// Problem Statement
/*Given an array nums with n objects colored red, white, or blue, sort them in-place
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
*/

// Easy Appraoch
/* Just like we did for previous question -> sort two colours, we can use the same easy appproach used for that
i.e Count all occureneces of the three nums and then just use loops to fill the array in proper order*/

// T.C -> O(n)
// S.C -> O(1)

void easy_sortColors(vector<int> &nums)
{
    int c0 = 0, c1 = 0, c2 = 0;

    // count
    for (int x : nums)
    {
        if (x == 0)
            c0++;
        else if (x == 1)
            c1++;
        else
            c2++;
    }

    // overwrite
    int idx = 0;

    for (int i = 0; i < c0; i++)
    {
        nums[idx++] = 0;
    }
    for (int i = 0; i < c1; i++)
    {
        nums[idx++] = 1;
    }
    for (int i = 0; i < c2; i++)
    {
        nums[idx++] = 2;
    }
}

// Optimal Appraoch
// Also called Dutch natonal flag problem
/* We can use an Three pointer approach, pointer i,j,k where and i and k start from 0 and j starts at from end and decreases
the logic we follow is if any index is 0 then swap them and move both k and i as zero will be in order
and if k is 1 then we just move k ahead i until we find number diff than 1 so that nummber can be swapped with either i or j
and if any index is 2, we will swap j and k index elements but in this case we do not increment k pointer as we dont know what value may come from j pointer
by following this we can easily sort the color array in place */

// T.C -> O(n)
// S.C -> O(1)

void sortColors(vector<int> &nums)
{
    int i = 0;
    int k = 0;
    int j = nums.size() - 1;

    while (k <= j)
    {
        if (nums[k] == 1)
        {
            // move until we find a number to swap with
            k++;
        }
        else if (nums[k] == 2)
        {
            swap(nums[j], nums[k]);
            j--;
            // do not increment k as we dont know what value may nums[j] hold
        }
        else
        {
            // nums[k]==0 we just move both ahead as we got zero
            swap(nums[i], nums[k]);
            i++;
            k++;
        }
    }
}

int main()
{
    vector<int> nums = {2, 1, 0, 0, 0, 2, 1};
    vector<int> nums1 = {2, 1, 0, 0, 0, 2, 1};
    easy_sortColors(nums);
    sortColors(nums1);
    for (auto a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : nums1)
    {
        cout << a << " ";
    }
    return 0;
}