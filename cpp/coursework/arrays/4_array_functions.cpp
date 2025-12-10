/*
 Common C++ Vector Functions:
 Size: arr.size()
 Max: Iterate and compare (or use std::max_element)
 Sum: Iterate and add (or use std::accumulate)
*/

#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int> &arr)
{
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int getSum(vector<int> &arr)
{
    int total = 0;
    for (int x : arr)
    {
        total += x;
    }
    return total;
}

int main()
{
    vector<int> nums = {5, 12, 7, 9, 3};

    cout << "Size of array: " << nums.size() << endl;
    cout << "Max element: " << getMax(nums) << endl;
    cout << "Sum of elements: " << getSum(nums) << endl;

    // In C++, the 'capacity' is how much memory is reserved,
    // 'size' is how many elements are actually in it.
    cout << "Capacity: " << nums.capacity() << endl;

    return 0;
}