# prblem statement
# We need to find the subarray that has the maximum sum.
# A subarray is simply an array inside another array.
# ex:-
# [-2, 1, -3, 4, -1, 2, 1, -5, 4]
# Possible subarrays: [-2, 1, -3], [-5, 4], or even the entire array itself.
# key point is that the subarray must be continuous.


# brute force method
# Using two loops to explore every possible subarray.
# We'll use a variable to track the largest sum found so far.
# Note: We only need to return the maximum sum, not the subarray itself.
# T.C -> O(n^2)
# S.C -> O(1)

def brute_force(nums):
    length = len(nums)
    maximum_sum = nums[0]

    for i in range(length):
        current_sum = 0
        for j in range(i, length):
            current_sum += nums[j]
            maximum_sum = max(current_sum, maximum_sum)
    return maximum_sum

# kadanes Algorithm
# This algorithm runs in a single loop and keeps a running sum.
# if running sum ever drops below zero, we reset it to zero.
# its an optimal approach to find the maximum subarray sum.
## T.C -> O(n)
## S.C -> O(1)

def better_approach(nums):
    length = len(nums)
    current_sum = nums[0]
    running_sum = 0

    for i in range(length):
        running_sum += nums[i]
        current_sum = max(running_sum, current_sum)
        if running_sum < 0:
            running_sum = 0
    return current_sum



nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(brute_force(nums))
print(better_approach(nums))
