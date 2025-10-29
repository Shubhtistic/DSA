# Given an array of integers nums, return the second-largest element in the array
# If the second-largest element does not exist, return -1
# We are not allowed to sort

# Quick Note:
# If we don't get it in the first attempt it's okay as the question looks easy, but is a bit complicated
# So try to understand the logic behind finding the second largest

# What we simply need to do is in a single check O(n) find the second smallest element
# What we can do is assume the first index as largest .. just assume, if it's not it will get updated in the loop
# We also need to check for the second smallest element
# So we need to check elements larger than all elements except the largest element


import math # for infinity
def second_largest(nums:list)-> int:
    lg=nums[0]
    slg=math.inf
    for i in range(1,len(nums)):
        if nums[i]>lg:
            slg=lg # the old largest now becomes second largest
            lg=nums[i]
        elif nums[i]>slg and nums[i]<lg:
            slg=nums[i]
    if(slg==math.inf):
        return -1
    return slg

nums=[1,1,1,1,2,8,8,7]
print(second_largest(nums))
