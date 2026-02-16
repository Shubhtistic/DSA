# Problem Statement
# Given a 0-indexed integer array nums and an integer target,
# return indices of the two numbers such that they add up to target.
# You may assume exactly one solution exists and you cannot use same element twice.

# Example:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]


# Easy / Brute Force Approach
# We use two loops and check every pair

## T.C -> O(n^2)
## S.C -> O(1)


def twoSum_brute(nums: list[int], target: int) -> list[int]:

    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]


# Optimal Approach
# We use hashmap (dictionary)
# store number and its index
# if target - curr number already seen -> we found answer

## T.C -> O(n)
## S.C -> O(n)


def twoSum_optimal(nums: list[int], target: int) -> list[int]:

    mp = {}

    for i in range(len(nums)):

        rem = target - nums[i]

        if rem in mp:
            return [mp[rem], i]

        mp[nums[i]] = i
