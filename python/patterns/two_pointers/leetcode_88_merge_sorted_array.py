# problem statement
# You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
# and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
# Merge nums1 and nums2 into a single array sorted in non-decreasing order.
# The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

# Example 1:
# Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
# Output: [1,2,2,3,5,6]
# Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
# The result of the merge is [1,2,2,3,5,6]

# Two Pointer Approach
"""Whenever we have to merge something we can use the two pointer approach to compare and merge the result properly
in this question we can see that nums1 needs to modified and returnned.
so m is elements in nums1 and after all are elements are zero padded to accomodate m+n space
nums1 has m+n space so it can hold its n elements and also the incoming n elements from nums2
So we ca say m= total_size-n nums1 has m-1 valid elements that we need merge properly and nums2 directly has n
if we look closely we can use the zero padded space in nums1 as if leaves size(nums1)-m space for other elements
what if we use those zeros to properly edit the nums 1 in place and return merged array
as the array is already sorted we will start from ends of both array for nums1 we will start from m-1 beacuse
remaining are zero only till index m-1 we have valid elements from nums1
so if we comapre from end as we have larger values due to sorting so we compare both arrays and then fill it from the back

IMP: we also need to take care of elements that may remain after first loop as a array may cantain all larger elements than other array
so the other array goes untouched so we also add those to avoid edge cases"""

# T.C -> O(n)


# S.C -> O(1) .. NO EXTRA SPACE USED


def merge(nums1: list[int], m: int, nums2: list[int], n: int) -> None:
    """
    Do not return anything, modify nums1 in-place instead.
    """

    if len(nums2) == 0:
        return None

    if len(nums1) == 0:
        nums1 = nums2
        return

    i = m - 1
    j = n - 1
    back = len(nums1) - 1

    while i >= 0 and j >= 0:
        if nums1[i] > nums2[j]:
            nums1[back] = nums1[i]
            back = back - 1
            i = i - 1
        else:
            nums1[back] = nums2[j]
            back = back - 1
            j = j - 1
    while i >= 0:
        nums1[back] = nums1[i]
        i = i - 1
        back = back - 1
    while j >= 0:
        nums1[back] = nums2[j]
        j = j - 1
        back = back - 1
