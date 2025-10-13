
# Description:
# You’re given an integer array nums, and you need to return another array answer
# such that each element at index i in answer is equal to the product of all the numbers
# in nums except nums[i]. You must solve it without using division, and the solution
# should run in O(n) time.
#
# In simple terms — for every element, multiply all other elements except that one.
# The catch is to do it efficiently without recalculating everything for each index.
# It’s a great problem to test your understanding of prefix and suffix product logic,
# and how to handle space optimization smartly.

# First, let's try the brute force method:
# In this, we make a copy list to store the products, since the original list
# gets modified after every iteration — causing multiplication with already modified values.
# Simply use two loops to store the product in the copy list.
# Use the condition if (i == j) to avoid self multiplication.
# It may also fail when the elements are very large (like powers of 10).
# We have to handle this test case carefully.
# T.C -> O(n^2)
# S.C -> O(n)

def brute_force(nums:list)->list:
    opt=list()
    
    for i in range(len(nums)):
        product=1
        for j in range(len(nums)):
            if(i==j):
                continue
            else:
                product=product*nums[j]
        opt.append(product)
    return opt

# okay so now let's try to make this thing faster
# brute force was just looping again n again for each element — too slow (O(n^2))
# so instead of doing the same work multiple times, let’s be a bit smart here

# idea is simple:
# for every index i, ans[i] should be product of all elements on its left * all elements on its right
# that’s it, nothing fancy

# so nums = [1,2,3,4]
# for 0th -> left = none, right = 2*3*4 = 24
# for 1st -> left = 1, right = 3*4 = 12
# for 2nd -> left = 1*2 = 2, right = 4
# for 3rd -> left = 1*2*3 = 6, right = none
# final = [24,12,8,6]
# boom done

# now to do this properly we make two arrays:
# left[i] = product of everything before i
# right[i] = product of everything after i

# left build (go left -> right)
# left[0] = 1 (nothing before it)
# left[1] = left[0]*nums[0] = 1
# left[2] = left[1]*nums[1] = 2
# left[3] = left[2]*nums[2] = 6
# left = [1,1,2,6]

# right build (go right -> left)
# right[3] = 1 (nothing after)
# right[2] = right[3]*nums[3] = 4
# right[1] = right[2]*nums[2] = 12
# right[0] = right[1]*nums[1] = 24
# right = [24,12,4,1]

# multiply both:
# answer[i] = left[i]*right[i]
# gives [24,12,8,6] — correct one

# now extra arrays kinda waste memory so we can do it cleaner
# step 1 -> fill ans with left product in one pass
# step 2 -> move from right to left and keep multiplying by a running product (right side)
# this way we don’t need right[] at all, just one variable for it

# final result same but now O(n) time and O(1) extra space
# no division, no extra loops, just neat and fast

# even works if nums has 0s, coz the side products handle it naturally

# quick recap so i don’t forget later:
# - each ans[i] = product of left part * right part
# - make prefix (left) and suffix (right)
# - can merge both steps to save space
# - O(n) time, O(1) space
# - clean, solid, and a fav in interviews


def optimal(nums):
    n = len(nums)
    res = [1] * n
    left_prod = 1
    for i in range(n):
        res[i] = left_prod
        left_prod *= nums[i]
    right_prod = 1
    for i in range(n - 1, -1, -1):
        res[i] *= right_prod
        right_prod *= nums[i]
    return res



nums = [1,2,3,4]
print(brute_force(nums))
print(optimal(nums))