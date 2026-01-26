#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// IMP NOTE:
/*Plaese Refer to 3sum(LeetCode 15) and 3sum closest(LeetCode16) to understand this Question
The Solution for Both is in this same folder, so take a look*/

// Problem Statement
/*Given an array arr[] of distinct integers of size n and a value sum,
the task is to find the count of triplets (i, j, k),
having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

Examples :
Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3).*/

// Two/Three Pointer Approach
/*We will use the same logic that we used for 3Sum And 3Sum Closest
We will first Sort the Array so we can move pointer easily based on sum and target comparison
WE will use one fixed pointer and Two moving pointers and Increment Counter if we find triplet_sum < target
We will check for triplet sum using start and end pointer if the triplet sum is lower than target then all triplets in that range are valid.
so we do (end - start) to count all valid triplet in that range and add it to our counter variable*/

// T.C -> O(n^2)
// S.C -> O(1)

long long countTriplets(int n, long long sum, long long arr[])
{
    // Your code goes here

    sort(arr, arr + n);
    long long c = 0;

    for (int f = 0; f < n - 2; f++)
    {
        // f -> fixed ptr

        int s = f + 1;
        int e = n - 1;

        while (s < e)
        {

            long long curr_sum = arr[f] + arr[e] + arr[s];

            if (curr_sum < sum)
            {
                // all pairs in this range are valid
                c = c + (e - s);
                s++;
            }
            else
            {
                e--;
            }
        }
    }

    return c;
}
int main()
{
    long long int test[5] = {1, 2, 3, 4, 5};

    cout << countTriplets(5, 12, test) << endl;
    return 0;
}