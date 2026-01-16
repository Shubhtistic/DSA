#include <vector>
#include <iostream>
using namespace std;

// Problem Statement
/*Given an integer array nums sorted in non-decreasing order,
remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​.
After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order.
The remaining elements beyond index k - 1 can be ignored.

Custom Judge:
The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation
assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/

// Two Pointer Approach
/*we make an make an pointer that starts from 1 because if array is of size 1 then it conatains no dupliacates as
it contains only one element so we can safey return that.
then we go in a loop and move the pointer only when we get a new value and not an duplicates
also we place that value in proper sequence using the same pointer
*/

// T.C -> O(n)
// S.C -> O(1)

int removeDuplicates(vector<int> &nums)
{
    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {

        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

int main()
{

    return 0;
}