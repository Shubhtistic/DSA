# Problem Statement
# Given an array nums with n objects colored red, white, or blue, sort them in - place
# so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
# We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
# You must solve this problem without using the library's sort function.

# Easy Appraoch
# Just like we did for previous question->sort two colours, we can use the same easy appproach used for that
# i.e Count all occureneces of the three nums and then just use loops to fill the array in proper order

# T.C->O(n)
# S.C->O(1)


def easy_sortColors(nums):
    c0 = 0
    c1 = 0
    c2 = 0

    # count
    for x in nums:
        if x == 0:
            c0 += 1
        elif x == 1:
            c1 += 1
        else:
            c2 += 1

    # overwrite
    idx = 0

    for i in range(c0):
        nums[idx] = 0
        idx += 1

    for i in range(c1):
        nums[idx] = 1
        idx += 1

    for i in range(c2):
        nums[idx] = 2
        idx += 1


## Optimal Approach -> 3 pointers
## This is also known as Dutch National Flag problem.
## At first it may feel confusing but once you see the pointer movement it makes sense.

## We use 3 pointers:
## start -> all elements before this must be 0
## mid   -> current element we are checking
## end   -> all elements after this must be 2

## So basically:
## left side  -> 0s
## middle     -> 1s
## right side -> 2s

## Now we move mid and check:

## If nums[mid] == 0:
## We swap it with start to push 0 to the left side.
## Then move both start and mid forward because that position is now correct.

## If nums[mid] == 1:
## It is already in correct middle position.
## Just move mid ahead.

## If nums[mid] == 2:
## We swap it with end to push 2 to the right side.
## Only move end backward.
## We DO NOT move mid here because the new value that came from end
## still needs to be checked.

## T.C -> O(n)  (single pass)
## S.C -> O(1)  (in-place sorting)


def optimal(nums: list) -> None:
    start = 0
    mid = 0
    end = len(nums) - 1

    while mid <= end:
        if nums[mid] == 0:
            nums[mid], nums[start] = nums[start], nums[mid]
            start += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        elif nums[mid] == 2:
            nums[mid], nums[end] = nums[end], nums[mid]
            end -= 1
