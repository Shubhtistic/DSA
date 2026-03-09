# Problem statement
# Given an integer array nums, find a subarray that has the largest product,
# and return the product.
# The test cases are generated so that the answer will fit in a 32-bit integer.
# Note that the product of an array with a single element is the value of that element.
#
# Example 1:
# Input: nums = [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
#
# Example 2:
# Input: nums = [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

# Brute Force Approach
# Use two loops to build all possible subarrays and find the highest product.
# T.C --> O(n^2)
# S.C --> O(1)


def max_product_brute(nums):
    max_product = float("-inf")

    for i in range(len(nums)):
        product = 1
        for j in range(i, len(nums)):
            product *= nums[j]
            max_product = max(product, max_product)

    return max_product


# Optimal Approch
# If we tink about the normal kadanes approach, the only thing annoying us is -ve's in the array
# as during product, +ve x -ve = small -ve value, -ve c -ve = big +ve value
# we have to somehow track the both maximum product even with -ve's being present
# what we can do is we can track min and maxm product in array
# we track min product in case a -ve arrives then that -ve will make that a big +ve value as -ve x -ve = big +ve

# T.C -> O(n)
# S.C -> O(1)


def maxProduct_optimal(self, nums: list[int]) -> int:
    maxp = nums[0]
    minp = nums[0]
    mp = nums[0]

    for i in range(1, len(nums)):
        v1 = maxp * nums[i]  # grows or decrease
        v2 = minp * nums[i]
        v3 = nums[i]  # grows or decrease
        maxp = max(v1, v2, v3)
        minp = min(v1, v2, v3)
        mp = max(maxp, minp, mp)
    return mp
