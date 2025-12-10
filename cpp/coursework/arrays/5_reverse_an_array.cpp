/*
 2 Pointers approach
 Start one pointer at 0 (left) and one at size-1 (right).
 Swap them and move them towards each other until they meet.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseArray(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "original ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    reverseArray(nums);

    cout << "original:- ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}