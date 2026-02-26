# Write a function that reverses a string. The input string is given as an array of characters s.
# You must do this by modifying the input array in-place with O(1) extra memory.
# Example 1:
# Input: s = ["h","e","l","l","o"]
# Output: ["o","l","l","e","h"]

# Approach
# We will use an easy two pointer approach, one pointer at start and one at end.
# start ptr moves right(increases) and end pointers moves left(decreases),
# we do this in a while loop until start<end and swap values at each iteration

# T.C -> O(n)
# S.C -> O(1)


def reverseString(s):
    start = 0
    end = len(s) - 1

    while start < end:
        s[start], s[end] = s[end], s[start]
        start += 1
        end -= 1


s = ["h", "e", "l", "l", "o"]
reverseString(s)
for item in s:
    print(item, end=" ")
