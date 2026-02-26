# Problem Statement
# Given an integer array nums, move all 0's to the end of it And
# while maintaining the relative order of the non-zero elements.
# Note that you must do this in-place without making a copy of the array.
# Example 1:
# Input: nums = [0,1,0,3,12]
# Output: [1,3,12,0,0]

# Approach
# What we we will do is we will just ignore zeros and place the non zero elements first and
# then the pointer reaches some length and from that length just insert remaining all with zeros
# Dry Run:
# Input: nums = [0,1,0,3,12]
# we just over write with non zero
# nums=[1,3,12,3,12]
# the pointer will be at 3rd index i.e 3(after 12)
# other loops fills that with zeros

# T.C -> O(n)
# S.C -> O(1)


def moveZeroes(nums):
    k = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[k] = nums[i]
            k += 1

    for i in range(k, len(nums)):
        nums[i] = 0
