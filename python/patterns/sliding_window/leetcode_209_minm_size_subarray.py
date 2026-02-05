"""Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target. 
If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1"""

#Sliding window Approach
"""As we can see this is an dynamic sliding window problem in which we have to find out a subarrays that have 
sum greater than target, and return length on smallest subarray that satisfies the condn

What we can do is start both ptrs low & high from zero 
then we will keep increasing high until we get an sum greater than target
Once we have an subarray then we try to increase the low ptrs i.e 
try to remove start elements from window to see how much can we minimize the subarray while still following the condition
one this condn failsi.e increase low ptr, then again we move high ptr to get more values and repeat same

I will Try to explain this using a real world analogy
We will take a example of an company that does xyz work and its required output in value
so we can map the companys work as sum and its required output as target i.e how much company needs to achieve
So lets Company starts hiring and keeps on hiring until ( adding more employees i.e High pointer increasing) 
Once Company Hits an the required Output they start firing people to see how much employes can they decrease until requied o/p does not drop
(correlated to increasing low ptrs to shrink subarray sum) after firing the required output may again need more employees
correlates to (add more new employees to cover up firing) then we follow the same step again again we find the least number of employees
that can meet our required target (final min length subarray satisfying sum>=target)"""

# T.C -> O(n) 
# Explanation even though we have nested loops because every increment of the ptrs
# moves it permanantly ahead i.e Each element is added once (by high) and removed once (by low)

# S.C -> O(1) .. No extra space used

def minSubArrayLen(target: int, nums: list[int]) -> int:
    low: int = 0
    high: int = 0
    sum: int = 0
    min_len = float("inf")

    while high < len(nums):
        sum = sum + nums[high]

        while sum >= target:
            min_len = min(min_len, high - low + 1)
            sum = sum - nums[low]
            low = low + 1
        high += 1

    if min_len == float("inf"):
        return 0
    return min_len
