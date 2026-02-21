#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Problem Statement
/*Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

// Brute Force Approach
/*For an subarray to find counts the best thing we can do is just use two loops.
the inner loop builds the subarray and we use an hashmap to see for that specific subarray does it contain k exact integers
if it exceeds k distinct integers we can easily break from that iteration as we cant find anymore distinct ints in that array
we use a hashmap because the size of hashmap tells us how many elements we have so we will store elements and keys and their counts as values*/

// T.C -> O(n^2)
// S.C -> O(n)

int subarraysWithKDistinct_brute(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i; j < nums.size(); j++)
        {
            mp[nums[j]]++;

            if (mp.size() == k)
            {
                count++;
            }
            if (mp.size() > k)
            {
                break;
            }
        }
        mp.clear();
    }

    return count;
}

// Optimal Approach -> Sliding Window with HashMap
/*To understand the optimal approach lets modify the problem statement.
Lets find the count of all subarrays where the distinct integers are less than or equal to k. Why? you will find out shortly.

Lets make a helper function which finds subarrays with distinct integers less than or equal to k.

Dry run:
Example: nums = [1,2,1,2,3], k = 2

If you follow a normal dry run for this using the logic we mentioned above,
you will find out we have 12 subarrays where there are less than or equal to k distinct integers.

Specially focus on the words "equal to k".
We found subarrays where there are less than or equal to k distinct integers.
So we already have the count of subarrays with exactly k also,
but it is included along with subarrays having less than k distinct integers.

So if somehow we were able to only keep the count of exactly k
and remove the less than k counts,
what can we do?

Maybe subtract the number of non-exactly-k subarrays.
How would we do that?

What if we run the function again but this time for k-1?

Now comes the magic.

Once we find the result for k-1,
what we are effectively doing is finding the number of subarrays where
distinct integers are less than or equal to k-1.

So when we subtract this value from our result for k,
we get the number of subarrays where it is exactly k.

Because:
help(k)  -> gives subarrays with <= k distinct
help(k-1)-> gives subarrays with <= k-1 distinct

Subtracting removes all subarrays with less than k distinct,
leaving only subarrays with exactly k distinct integers.
*/

// T.C -> O(n)
// S.C -> O(n)

int help(vector<int> &nums, int k)
{
    int low = 0;
    int c = 0;
    unordered_map<int, int> mp;

    for (int high = 0; high < nums.size(); high++)
    {
        mp[nums[high]]++;

        while (mp.size() > k)
        {
            mp[nums[low]]--;
            if (mp[nums[low]] == 0)
            {
                mp.erase(nums[low]);
            }
            low++;
        }
        if (mp.size() <= k)
        {
            c = c + (high - low + 1);
        }
    }
    return c;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return help(nums, k) - help(nums, k - 1);
}

int main()
{
    // thanks for visting
    return 0;
}