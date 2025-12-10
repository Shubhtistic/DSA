/*
 Problem: Find the Minimum and Maximum element in an array.
 Approach: Single Scan.
 We maintain two variables 'min' and 'max'.
 We iterate through the array ONCE, updating both as we go.
 Time Complexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

void findMinMax(vector<int> &arr)
{
    // if arrays is empty
    if (arr.empty())
    {
        cout << "Array is empty " << endl;
        return;
    }

    // Initialize min and max with the first element
    int minVal = arr[0];
    int maxVal = arr[0];

    // Single loop starting from 2nd element
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i]; // new minm
        }
        else if (arr[i] > maxVal)
        {
            maxVal = arr[i]; // new maxm
        }
    }

    cout << "Minm value : " << minVal << endl;
    cout << "maxm value: " << maxVal << endl;
}

int main()
{
    vector<int> nums = {5, 8, 1, 10, 50, 2, 9};

    cout << "Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    findMinMax(nums);

    return 0;
}