# PROBLEM STATEMENT:
# Given an integer array nums sorted in non-decreasing order,
# remove the duplicates in-place so that each unique element appears only once.
# The relative order should remain the same.
# After removing duplicates, return the number of unique elements k.
# The first k elements of nums should have the unique numbers in sorted order.
# The remaining elements beyond index k-1 can be ignored.

# Solution
# here we just have to modify the array in place and remove duplicates
# once all unique elements are arranged properly in relative order, the rest don’t matter
# we can check adjacent elements, and whenever we find a unique one, we move it ahead in the array
# if we do nums[i]==nums[i+1], we might go out of range
# and if we do nums[i]==nums[i-1], we can miss the first element
# easy fix — since array is sorted, we keep the first element as it is
# start counter = 1 and loop from i=1 till end
# whenever nums[i]!=nums[i-1], we found a new unique element
# so we set nums[counter]=nums[i] and increment counter

# example
# nums = [1,1,2,3,4,4]
# nums[0] stays same (1)
# i=1 → nums[1]==nums[0] → skip (duplicate)
# i=2 → nums[2]!=nums[1] → unique → nums[1]=nums[2] → [1,2,2,3,4,4], counter=2
# i=3 → nums[3]!=nums[2] → unique → nums[2]=nums[3] → [1,2,3,3,4,4], counter=3
# i=4 → nums[4]!=nums[3] → unique → nums[3]=nums[4] → [1,2,3,4,4,4], counter=4
# i=5 → nums[5]==nums[4] → skip
# final array till counter (4) → [1,2,3,4]
# so k=4

def solution(nums:list)-> int:
    counter=1
    for i in range(1,len(nums)):
        if(nums[i]==nums[i-1]):
            continue
        else:
            nums[counter]=nums[i]
            counter+=1
    return  counter

nums=[1,1,1,2,3,4,5,6,6]
print(solution(nums))