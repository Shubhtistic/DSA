#include <iostream>
#include <vector>
using namespace std;

// Problem Statement
/*Given an array of integers arr[]  and a number k.
Return the maximum sum of a subarray of size k.
Note: A subarray is a contiguous part of any given array.

Examples:
Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.

Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
*/

// Brute Force Approach
/*We can use the two pointer pattern. We will low at 0 and high at the window size that we are given
So we can use nested loops to gradually shift our window, calculating sum for every subarray
*/

// T.C -> O(n^2)
// S.C -> O(1)

int bruteForce(vector<int> &arr, int k)
{
    // code here
    int low = 0;
    int high = k - 1;
    int mx = arr[0];

    // now we slide it
    while (high < arr.size())
    {
        int sum = 0;
        for (int i = low; i <= high; i++)
        {
            sum = sum + arr[i];
        }

        // new sum
        mx = max(sum, mx);
        low++;
        high++;
    }

    return mx;
}

// Optimal Solution
/*We can use the sLiding Window pattern, Which is just a subset of two pointer pattern
we can optimize the brute Force Approach, if we take a look we are just sliding a window of fiixed size
so for evry slide we calculate sum and then move both indexes so we lose one elememt and add another one
So we can just use this exact logic to Optmize it, what if we subtract the lost element and then add the new element.
By doing this we can easily Calculate sum for each subarray in a single pass And in linear time
Dry run
arr=[2,3,5,6,2,4]
lets assume k=2
so fixed window of size 2
first a loop that calculates inital window
for(from 0 to k-1)-> 2+3
sum=5
max_sum=5;
now we want to slide the window so we increase both low and high
so new window is [3,5] 2 is lost and 5 is added
so we want 3+5 which is 8 , we already have from intial window 2+3 = 5,
so we lost 2 and added 5 , so we can do 5 -2 + 5 = 8 .. exact answer
And so on for remaining windows
*/

// T.C -> O(n)
// S.C -> O(1)
int maxSubarraySum(vector<int> &arr, int k)
{
    // code here

    int i = 0;
    int j = k - 1;
    int sum = 0;

    for (int p = i; p <= j; p++)
    {
        sum = sum + arr[p];
    }

    int mx = arr[0];
    mx = max(mx, sum);

    while (j != arr.size() - 1)
    {

        i++;
        j++;

        sum = sum - arr[i - 1] + arr[j];
        mx = max(sum, mx);
    }

    return mx;
}

int main()
{
    vector<int> abd = {1, 2, 3, 4, 6, 7, 8};

    cout << maxSubarraySum(abd, 2);

    return 0;
}