/*
 Linear Search: A very simple Algo, just iterates through the vector/array one by one to find the target.
 Time Complexity: O(n)
 Used when the array is NOT sorted.
*/

#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &arr, int target)
{
    // Basic loop to check every element
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main()
{
    vector<int> nums = {10, 50, 30, 70, 80, 20};
    int target = 30;

    int result = linearSearch(nums, target);

    if (result != -1)
    {
        cout << " found at index " << result << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}