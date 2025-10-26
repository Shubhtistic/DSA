# Given a non-empty array of integers nums
#  every element appears twice except for one. Find that single one.
# You must implement a solution with a linear runtime complexity and only O(1) space

# lets first use an easy method an hash map to store the numbers with counts
# if any number has count of 1, we got the answer
# T.C -> O(n)
# S.C -> O(1)

def easy_method(nums:list) -> int:
    m=dict()
    for it in nums:
        if it in m:
            m[it]+=1
        else:
            m[it]=1
    s=None
    for key,value in m.items():
        if value==1:
            s=key
    return s

# lets try to optimize this 
# should we try bitwise operations as we are restricted to O(1) space
# we know xor operation that same numbers cancel out each other
# stated in question that all numbers repeat expect one 
# so if we do xor all the multiple numbers will cancel out each other and only unique one will remain
# xor -> associative and cumulative
# T.C -> O(n)
# S.C -> O(1)


def optimal(nums:list)-> int:
    x=0
    for t in nums:
        x^=t
    return x

l=[1,2,3,4,4,3,2]
print(optimal(l))
print(easy_method(l))

