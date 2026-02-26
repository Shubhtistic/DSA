# Problem Statement
# Given a string ‘N’ that represents a number,
# you need to check if the given number is a strobogrammatic number or not.
# A strobogrammatic number is a number that looks the same when rotated by 180 degrees.
# In other words, a number that when rotated upside down appears the same is a strobogrammatic number.
# For example:
# ‘986’ is a strobogrammatic number because on rotating ‘986’ by 180 degrees, ‘986’ will be obtained.


# Simple Approach or Brute Approach
# From above we can say that the numbers 0, 1, 6, 8, 9 are strobogrammatic.
# So if any other number appears, it is rejected at that moment.
# What we can do is run a simple loop which converts the numbers into their proper strobogrammatic form
# and directly reject other numbers as well.
# Then we reverse and check if they are the same.

# T.C -> O(n)
# S.C -> O(n)


def simple_approach(n: str) -> bool:
    n1 = list(n)

    for i in range(len(n)):
        if n1[i] == "6":
            n1[i] = "9"
        elif n1[i] == "9":
            n1[i] = "6"
        elif n[i] == "0" or n[i] == "8" or n[i] == "1":
            continue
        else:
            return False

    k = 0
    j = len(n) - 1
    while k <= j:
        n1[k], n1[j] = n1[j], n1[k]
        k += 1
        j -= 1

    if "".join(n1) == n:  # convert list of strings into a single string
        return True

    return True


# Optimal Two Pointer Approach
# If you think closely, a strobogrammatic number is simply flipping a number and reversing it.
# So it is basically flipping it and checking if it forms a valid palindrome or not.
# For example: 9 8 6
# After flip -> 6 8 9
# Now reverse -> 9 8 6

# What we will do:
# We will use two pointers, one at the end and one at the start.
# We will check if the strobogrammatic counterpart of a digit exists at the other pointer.
# If not, return False.

# T.C -> O(n)
# S.C -> O(1)


def optimal(n: str) -> bool:
    i = 0
    j = len(n) - 1
    l = ["1", "8", "0"]

    while i <= j:
        if n[i] == "6":
            if n[j] != "9":
                return False
            else:
                i += 1
                j -= 1
        elif n[i] == "9":
            if n[j] != "6":
                return False
            else:
                i += 1
                j -= 1
        elif n[i] in l:
            if n[i] != n[j]:
                return False
            else:
                i += 1
                j -= 1
        else:
            return False

    return False

    pass


s = "123456"
s1 = "986"

if simple_approach(s):
    print("Strobogramatic", s)
else:
    print("Not Strobogrammatic")

if optimal(s):
    print("Strobogramatic", s)
else:
    print("Not Strobogrammatic")

print("=============================================================")
print("Using optimal")

if simple_approach(s1):
    print("Strobogramatic", s1)
else:
    print("Not Strobogrammatic")

if optimal(s1):
    print("Strobogramatic", s1)
else:
    print("Not Strobogrammatic")
