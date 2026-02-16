# Problem statement
# Given a 0-indexed integer array nums of length n and an integer target,
# return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

# Example 1:
# Input: nums = [-1,1,2,3,1], target = 2
# Output: 3
# Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
# - (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
# - (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target
# - (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
# Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target.

# Easy / Brute Approach
# We will use the two loops method -> one outer loop and one inner loop to check each subarray

## T.C -> O(n^2)
## S.C -> O(1)


def countPairs_brute(nums: list[int], target: int) -> int:

    num = 0
    for i in range(0, len(nums)):
        for j in range(i + 1, len(nums)):
            if (nums[i] + nums[j]) < target:
                num = num + 1

    return num


## Two Pointers Approach
# Whenever we approach a two pointer question we also consider the possibilty of sorting the array
# over here can it help us -> yes it does
# How -> When we sort the array we arrange the array in order so by that logic
# every subarray will then have a start and end range
# so if we think closely once we sort the array large element will be towards end and smaller at start
# so if that entire range is smaller than target we can say that all subarrays in range are also valid
# by that logic we check all the subarrays and find the count efficiently

## T.C -> O(nlogn)
# S.C -> O(1)


def countPairs_optimal(nums: list[int], target: int) -> int:
    nums.sort()
    start = 0
    end = len(nums) - 1
    count = 0

    while start < end:
        if nums[start] + nums[end] < target:
            count = count + (end - start)
            start = start + 1

        elif nums[start] + nums[end] >= target:
            end = end - 1

    return count
