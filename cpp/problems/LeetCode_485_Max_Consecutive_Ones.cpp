// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Simple Logic
// Start with count = 0 and max = 0.
// Go through the array element by element.
// If it’s 1 → increase current count and update max if needed.
// If it’s 0 → reset count to 0.
// After checking all elements, return the max consecutive 1s.
#include <iostream>
#include <vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int mxc = 0;
    int count = 0;
    for (auto item : nums)
    {
        if (item == 1)
        {
            count++;
            mxc = max(count, mxc);
        }
        else
        {
            count = 0;
        }
    }
    return mxc;
}
int main()
{
    vector<int> vc = {1, 1, 1, 1, 1, 0, 0, 1, 0};
    cout << findMaxConsecutiveOnes(vc) << endl;

    return 0;
}