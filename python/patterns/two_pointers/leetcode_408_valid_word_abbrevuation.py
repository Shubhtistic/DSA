## Problem Statement
# A string can be shortened by replacing any number of non-adjacent,
# non-empty substrings with their lengths (without leading zeros).

# For example, the string "implementation" can be abbreviated in several ways, such as:
# "i12n" -> ("i mplementatio n")
# "imp4n5n" -> ("imp leme n tatio n")
# "14" -> ("implementation")
# "implemetation" -> (no substrings replaced)
# Invalid abbreviations include:

# "i57n" -> (i mplem entatio n, adjacent substrings are replaced.)
# "i012n" -> (has leading zeros)
# "i0mplementation" (replaces an empty substring)


## two Pointer Approach
#  we are given two strings one contanining full word and other containing abbreviation of that word
# so if you think deeply we can use the two pointer approach here
# whhat we can do is we will pointer for both string at start until their character are same we move them normally and
# when we encounter a number we parse that number and move the original word that many times.
# We will try to undestand this with a dry run of any above given example
# lets say
# word=implemetation
# abbr=i12n

# Dry Run:
# both ptrs start at 0
# 1st iteration: both chars are same move both ahead

# 2nd iteratiion: chars aree not same as abbr has a digit, so we extract that digit and move word that many times
# the number turned out be 14, move word ptr 14 steps ahead
# now word ptr is at n( after 14 steps)

# 3rd iteration: again both are same , move both
# now both ptr are equal to size of their respective strings
# so we can this is valid abbr for this word

# T.C -> O(n)
# S.C -> O(1)


def validWordAbbreviation(self, word: str, abbr: str) -> bool:
    w: int = 0
    ab: int = 0

    while w < len(word) and ab < len(abbr):
        if word[w] == abbr[ab]:
            # move both ptrs ahead
            w = w + 1
            ab = ab + 1
        elif abbr[ab].isdigit():
            if abbr[ab] == "0":
                return False
            num: int = 0
            while ab < len(abbr) and abbr[ab].isdigit():
                num = (num * 10) + int(abbr[ab])
                ab = ab + 1
            w = w + num
            # increase word pointer as much as the number

            # check if word ptr is out of bouds after this
            if w > len(word):
                return False
        else:
            return False
    if ab == len(abbr) and w == len(word):
        return True
    return False
