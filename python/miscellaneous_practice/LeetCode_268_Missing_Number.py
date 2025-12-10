# Given an array nums containing n distinct numbers in the range [0, n]
#  return the only number in the range that is missing from the array.
# Example 1:
# Input: nums = [3,0,1]
# Output: 2
# Explanation:
# n = 3 since there are 3 numbers, so all numbers are in the range [0,3]
# 2 is the missing number in the range since it does not appear in nums

# solution:
# we will simply make an set which contains all the elements
# and after that in a loop simply check if it contains the number from given range 0-n

# S.C -> O(n) .. worst case if all elements are unique
# T.C -> O(2n) => O(n)
def easy_approach(nums:list)->int:
    s=set()
    for t in nums:
        s.add(t)
    ms=None
    for i in range(0,len(nums)+1):
        if i not in s:
            ms=i
            break
    return ms

# can we optimize the code, earlier we used set for simplicity
# we can use the xor logic
# xor logic:
#  if both bits are same -> 0
#  if both bits are different
# it is cumutative and associative
# so we simply chcek if the array has same xor value as that of array range 
# as the question says the numbers are expected to be in the range [0,n]
# if no numbers are missig then both should have same xor values 
# So, if we XOR all numbers from 0..n, and also XOR all numbers in the array,
# every number that appears twice will cancel out (become 0),
# and the one number missing (which appears only once) will remain.
# Example:
# nums = [3, 0, 1]
# full range = [0, 1, 2, 3]
# missing = 2
# Let's XOR all of them step by step:
# Step 1: XOR of all numbers from 0 to n
# 0 ^ 1 ^ 2 ^ 3
# Step 2: XOR of all elements in array
# 3 ^ 0 ^ 1
# Step 3: XOR both results
# (0 ^ 1 ^ 2 ^ 3) ^ (3 ^ 0 ^ 1)
# Reordering (since XOR order doesn’t matter):
# (0 ^ 0) ^ (1 ^ 1) ^ (3 ^ 3) ^ 2
# → 0 ^ 0 ^ 0 ^ 2
# → 2  ← missing number
# -------------------------------
# Example of how XOR works bitwise:
# 2 = 10 (in binary)
# 3 = 11 (in binary)
#  1 0   (2)
# ^1 1   (3)
# ----
#  0 1   (1)
# So, 2 ^ 3 = 1

# S.C -> O(1)
# T.C -> O(n)
def optimal(nums):
    n = len(nums)
    xor_all = 0
    xor_nums = 0

    # XOR all numbers from 0 to n
    for i in range(n + 1):
        xor_all ^= i

    # XOR all numbers present in the array
    for num in nums:
        xor_nums ^= num

    # The remaining XOR result is the missing number
    return xor_all ^ xor_nums

# there is an another optimal approch
# simply find sum of the array and the range subtract it and the answer is the missing number
# example
#nums = [3, 0, 1]
# n = len(nums) = 3
# Full range sum = 0 + 1 + 2 + 3 = 6
# Array sum = 3 + 0 + 1 = 4
# Missing number = 6 - 4 = 2
# T.C -> O(n)
# S.C -> O(1)

def optimal_using_sum(nums:list)->int:
    array_sum=0
    for item in nums:
        array_sum+=item
    range_sum=0
    for i in range(0,len(nums)+1):
        range_sum+=i
    return range_sum-array_sum

l=[1,2,3,4,5,0]

print(easy_approach(l))
print(optimal(l))
print(optimal_using_sum(l))

