/*
 Definition: An Array is a collection of elements of the same type stored in contiguous memory.

 In C++, we have two main types:
 1. Raw Arrays (int arr[5]): Fixed size, fast, cannot grow.
 2. std::vector (vector<int>): Dynamic size, can grow/shrink, standard for C++ and widely used in place of Raw Arrays.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // raw Array -> fixed size
    int rawArr[5] = {1, 2, 3, 4, 5};
    cout << "raw Array element " << rawArr[0] << endl;

    // C++ vector -> dynamic array
    vector<int> nums = {10, 20, 30};

    // Operation example -> insert at end i.e appending a value
    nums.push_back(40);

    // Operation example -> Access elements (direct access through index)
    cout << "First element: " << nums[0] << endl;
    cout << "Last element: " << nums.back() << endl;

    // Operation -> Insert at a specific position (begin + index)
    // inserting 15 at index 1
    nums.insert(nums.begin() + 1, 15);

    // Operation: Delete from a specific position
    // Deleting element at index 2
    nums.erase(nums.begin() + 2);

    cout << "vector values: ";
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}