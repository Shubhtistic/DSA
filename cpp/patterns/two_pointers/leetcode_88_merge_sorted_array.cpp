#include <iostream>
#include <vector>
using namespace std;

// problem statement
/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/

// Simple OR Brute Foorcce approach
/* As given in the qiestion we can see that array num1 contains the m elements and nums 2 contains remaining n elements
and they are already in non decreasing ( ascending ) order, and we have modify array num1 to return final array
so what if we make a another small array that conatains the m elements from num1 as renaming elements are zero padded to get n+m length
and we compare num1_copy and num2 and fill the num1 array
*/
// T.C -> O(n+m)
// S.C -> O(m)
void brute_force(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums1_copy(nums1.size() - n);
    // as we know nums1 size is m+n contains m elements and other places are vacant(zero padded)
    for (int i = 0; i < nums1.size() - n; i++)
    {
        nums1_copy[i] = nums1[i];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nums1_copy.size() && j < nums2.size())
    {
        if (nums1_copy[i] < nums2[j])
        {
            nums1[k] = nums1_copy[i];
            i++;
            k++;
        }
        else
        {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }

    while (i < nums1_copy.size())
    {
        nums1[k] = nums1_copy[i];
        i++;
        k++;
    }

    while (j < nums2.size())
    {
        nums1[k] = nums2[j];
        j++;
        k++;
    }
}

// Optimal Approach
/* If we think a bit different then we can see the data is already sorted and given to us and the num1 array is zero padded,
after m elements, so what if we start at m and n elements but from the back and also add elements largest elements first at back first.
this way we can do it in place and no extra space is needed. Lets try to code that.
*/

// T.C -> O(n+m)
// S.C -> O(1)

void optimal_merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int back = nums1.size() - 1;
    int i = m - 1;
    int j = n - 1;

    // IMP -> Dont forget the i>=0 and j>=0 condition as we also need to access the 0th index
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[back] = nums1[i];
            back--;
            i--;
        }
        else
        {
            nums1[back] = nums2[j];
            back--;
            j--;
        }
    }

    while (i >= 0)
    {
        nums1[back] = nums1[i];
        back--;
        i--;
    }
    while (j >= 0)
    {
        nums1[back] = nums2[j];
        back--;
        j--;
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3;
    int n = 3;

    brute_force(nums1, m, nums2, n);

    cout << "after brute force merge: ";
    for (int x : nums1)
    {
        cout << x << " ";
    }
    cout << endl;

    nums1 = {1, 2, 3, 0, 0, 0};

    optimal_merge(nums1, m, nums2, n);

    cout << "after optimal merge ";
    for (int x : nums1)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
