/*
 binary search: efficiently finds an element by dividing the search interval in half, comparig values either going left or right to find the value.
 imp  condition: The array/vector MUST be sorted first.
 Time Complexity: O(log n)
*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid; // found
        }
        else if (target < arr[mid]) {
            high = mid - 1; // Look in left half
        }
        else {
            low = mid + 1;  // Look in right half
        }
    }
    return -1; // not found
}

int main() {
    vector<int> nums = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; 
    // sorted data
    int target = 23;

    int result = binarySearch(nums, target);

    if (result != -1) {
        cout << "found at index: " << result << endl;
    } else {
        cout << "not found" << endl;
    }

    return 0;
}