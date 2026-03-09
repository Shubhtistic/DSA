# Problem Statement
# Given an integer array nums, find the subarray with the largest sum, and return its sum.
#
# Example 1:
# Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
# Output: 6
# Explanation: The subarray [4,-1,2,1] has the largest sum 6.
#
# Example 2:
# Input: nums = [1]
# Output: 1
# Explanation: The subarray [1] has the largest sum 1.

# What the question states
# We have to return a contiguous subarray that has the highest sum.

# Brute force approach
# Use two loops to build all possible subarrays and find maximum sum.
# T.C -> O(n^2)
# S.C -> O(1)


def maxSubArray(self, nums: list[int]) -> int:
    best = nums[0]

    for i in range(len(nums)):
        sum = 0
        for j in range(i, len(nums)):
            sum = sum + nums[j]
            best = max(sum, best)
    return best


# =======================================================================================================================

# Optmial Approach
# Using the kadanes, Acc to kadanes algo we move index by index one at a time
# doing we have two options either add the current index to previous sum or start new whichever is biggest gets prefered
# we follow this until the end and get our maximum sum

# T.C -> O(n)
# S.C -> O(1)


def maxSubArray_optimal(self, nums: list[int]) -> int:
    best = nums[0]
    max_sum = nums[0]
    for i in range(1, len(nums)):
        v1 = best + nums[i]  # add to see if this become bigger
        v2 = nums[i]  # maybe this alone is bigger so it starts new subarray to track
        best = max(v1, v2)
        max_sum = max(max_sum, best)
    return max_sum
