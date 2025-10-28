# Given an integer array nums, rotate the array to the right by k steps, where k is non -ve
# Example 1:
# Input: nums = [1,2,3,4,5,6,7], k = 3
# Output: [5,6,7,1,2,3,4]
# Explanation:
# rotate 1 step to the right: [7,1,2,3,4,5,6]
# rotate 2 steps to the right: [6,7,1,2,3,4,5]
# rotate 3 steps to the right: [5,6,7,1,2,3,4]

# simple approach 
# what we can simply observe is that we need to bring the last k elements to the front 
# and shift all elements by k towards the right 
# example: nums = [1,2,3,4,5,6,7], k = 3
# we simply move the last k=3 elements to the front and shift all others by k towards right
# what we can do is first make an array that stores the non-k elements i.e. the elements that are not to be shifted
# and then run a loop and replace the last k elements one by one to the front
# and then add the stored non-k elements after that one by one
# example: nums = [1,2,3,4,5,6,7], k = 3
# non_k_array = [1,2,3,4] ... elements till n-k, in this case 7-3 = 4 (3rd index)
# by n we mean the length of the array → n = len(array)
# then add k elements to the front, nums now becomes
# nums = [5,6,7,4,5,6,7]
# after this, we add non_k elements after them, nums becomes
# nums = [5,6,7,1,2,3,4] ... exact answer that we needed

# we also avoid the edge case if k == n as it is simply a full rotation
# array just becomes like it was initially, so essentially no change
# very imp case: if k > n we use k = n % k as the rotation repeats
# logic: rotation repeats for every length = n
# let's say or assume length = 7
# so rotation repeats after 7 and for every multiple of 7
# example k = 9 → k = 7 + 2 
# example k = 20 → k = 7 + 7 + 6 
# that’s why we take modulo — divide by 7 and the remainder is the number of rotations to do

# S.C -> O(n)
# T.C = O(n-k + n-k + k) -> O(2n - k) -> O(n-k)
# so, T.C -> O(n)

def easy_method(nums: list, k: int):
    # handle edge cases
    if len(nums) == k:
        return
    if len(nums) == 1:
        return
    if len(nums) < k:
        k = k % len(nums)

    # change in place
    non_k = list()
    # S.C -> O(k), and in the worst case k = n-1 .. we handled the n == k edge case
    # so technically S.C(n-1) = S.C -> O(n)

    for i in range(0, len(nums) - k):
        non_k.append(nums[i])
        # never use non_k[i] with an empty list 
        # T.C -> O(n-k)
    
    # now let's use a tracker to start from 0 to k, so we can bring the last k elements to front
    counter = 0
    for i in range(len(nums) - k, len(nums)):
        nums[counter] = nums[i] 
        # 1st element from the last k elements ... and so on till the last element of k
        counter += 1
        # T.C -> O(k)

    # now again let's use counter variable as it will be at the position after the elements
    # also a variable to start from the 0th index of non_k list
    t = 0
    for i in range(counter, len(nums)):
        nums[i] = non_k[t]
        t += 1
        # T.C -> O(n-k)


# Now can we optimize the solution to not have extra space?
# we can maybe use reversing 
# we can reverse non-k and k elements and then reverse the entire array
# example of how it works ex: [1,2,3,4,5,6,7]
# k = 3 .. right shift all elements by 3
# so we reverse the last k elements [7,6,5] and reverse remaining [4,3,2,1]
# the array now looks like [4,3,2,1,7,6,5]
# now we reverse the entire array 
# so it looks like [5,6,7,1,2,3,4] .. correct output

def optimal(nums: list, k: int):
    nums[len(nums)-k:] = reversed(nums[len(nums)-k:])
    nums[:len(nums)-k] = reversed(nums[:len(nums)-k])
    nums[:] = nums[::-1]


nums = [1,2,3,4,5,6,7]
nums2 = [1,2,3,4,5,6,7]
easy_method(nums, 3)  # given k=3
print(nums)  # O/P : [5, 6, 7, 1, 2, 3, 4] 
optimal(nums2, 3)
print(nums2)
