#problem statement
#
# A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
# and removing all non-alphanumeric characters,
# it reads the same forward and backward. Alphanumeric characters include letters and numbers.
# Given a string s, return true if it is a palindrome, or false otherwise.
# Example 1:
# Input: s = "A man, a plan, a canal: Panama"
# Output: true
# Explanation: "amanaplanacanalpanama" is a palindrome.
# Example 2:

# Input: s = "race a car"
# Output: false
# Explanation: "raceacar" is not a palindrome.

# Two Pointer
"""
What we can dod is take take two converging ptrs, one from end index and one from start index
then we can ignore spaces and alphanumeric value and compare if the word are same from front and back
as palindromes are symmetrical about the midpoint
"""
# T.C -> O(n)
# S.C -> O(1)

def isPalindrome(self, s:str)->bool:
    st:int=0 # start
    e:int=len(s)-1

    while(st<e):
        if(s[st]==' ' or not s[st].isalnum()):
            st=st+1
            continue
        elif(s[e]==' ' or not s[e].isalnum()):
            e=e-1
            continue
        else:
            if(s[st].lower()!=s[e].lower()):
                return False
            else:
                st=st+1
                e=e-1
    return True



    