/*
 Logic: Check if every element is smaller than or equal to the next one.
 If we find ANY element that is greater than the one after it, the array is NOT sorted.
*/

#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int> &arr)
{
    // Loop up to size-1 because we compare with i+1
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> sortedNums = {10, 20, 30, 40, 50};
    vector<int> unsortedNums = {10, 20, 5, 40, 50};

    if (isSorted(sortedNums))
        cout << "array 1 is sorted" << endl;
    else
        cout << "array 1 is not sorted" << endl;

    if (isSorted(unsortedNums))
        cout << "array 2 is sorted" << endl;
    else
        cout << "array 2 is not Sorted" << endl;

    return 0;
}