# Problem Statement
# Given a 1-indexed sorted array numbers and a target,
# return indices (1-based indexing) of the two numbers such that they add up to target.
# Exactly one solution exists.

# Example:
# Input: numbers = [2,7,11,15], target = 9
# Output: [1,2]


# Easy / Brute Force Approach
# check every pair using 2 loops

## T.C -> O(n^2)
## S.C -> O(1)


def twoSum2_brute(numbers: list[int], target: int) -> list[int]:

    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            if numbers[i] + numbers[j] == target:
                return [i + 1, j + 1]


# Optimal Approach (Two Pointers)
# since array already sorted
# keep one ptr at start and one at end
# if sum small -> move start
# if sum big -> move end
# if equal -> return ans

## T.C -> O(n)
## S.C -> O(1)


def twoSum2_optimal(numbers: list[int], target: int) -> list[int]:

    start = 0
    end = len(numbers) - 1

    while start < end:

        s = numbers[start] + numbers[end]

        if s == target:
            return [start + 1, end + 1]

        elif s < target:
            start = start + 1

        else:
            end = end - 1
