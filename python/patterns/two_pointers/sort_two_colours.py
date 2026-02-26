# Note:- the question is kind of a prerequisite for leetcode 75 -> sort color
# if it feels too easy you may skip

# Problem statement
# we will be given an array of 0s and 1s we have to sort them without using any library function


# Straightforward easy approach
# we can just count number of 0s and 1s and then just fill the array with that number of 0s and 1s

# T.C -> O(n)
# S.C -> O(1)


def easy_method(nums):
    os = 0
    zs = 0

    for i in range(len(nums)):  # T.C -> O(n)
        if nums[i] == 0:
            zs += 1
        else:
            os += 1

    # T.C -> O(z) .. no of zeros
    # Worst Case -> O(n) .. if all elements are zeros
    for i in range(zs):
        nums[i] = 0

    # T.C -> O(ones) .. no of ones
    # Worst Case -> O(n) .. if all elements are ones
    for i in range(zs, len(nums)):
        nums[i] = 1


# Actual Two Pointer Approach
# With the two pointers that we have we can perform in place substitution
# we can use two pointers at extreme ends, if an end element is already 1 then we shift back (decrease pointer) until we find zero and
# same logic from front pointer and then we replace them. Lets try Coding it

# T.C -> O(n)
# S.C -> O(1)


def sort_colours(nums):
    i = 0
    j = len(nums) - 1

    while i < j:
        if nums[i] == 0:
            i += 1
        elif nums[j] == 1:
            j -= 1
        else:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1


nums = [0, 1, 1, 1, 0, 0, 1, 1]
nums1 = [0, 1, 1, 1, 0, 0, 1, 1]

easy_method(nums)
sort_colours(nums1)

print("nums")
for a in nums:
    print(a, end=" ")

print("\nnums1")
for a in nums1:
    print(a, end=" ")
