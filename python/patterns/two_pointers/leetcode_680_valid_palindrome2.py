# Given a string s, return true if the s can be palindrome
#  after deleting at most one character from it.

# Example 1:
# Input: s = "aba"
# Output: true
# Example 2:

# Input: s = "abca"
# Output: true
# Explanation: You could delete the character 'c'.

# Two Pointer Approach
"""WE use the same logic we used for valid palindrome 1, its availabe in the repo take a look.
we use the helper function to check if a string is palindrome or not,
but only use that function is we find non matching elements i.e its not palindromic in main loop
so we pass both left-- and right++ pointer to see if any palindromic combination can be made from that"""


def pal(i: int, j: int, s: str) -> bool:
    while i < j:
        if s[i] == s[j]:
            i += 1
            j -= 1
        else:
            return False
    return True


def validPalindrome(s: str) -> bool:
    start = 0
    end = len(s) - 1

    while start < end:
        if s[start] == s[end]:
            start += 1
            end -= 1
        else:
            return pal(start + 1, end, s) or pal(start, end - 1, s)
    return True


s = "madam"

if validPalindrome(s):
    print("YES")
