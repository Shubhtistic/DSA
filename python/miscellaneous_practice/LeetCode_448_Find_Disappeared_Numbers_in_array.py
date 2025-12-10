## in this question we are given an array which n elemeents 
## in the given range 1 to n 
## we have to find missing numbers in the entire array
## Input: nums = [4,3,2,7,8,2,3,1]
## Output: [5,6]

## easy approch
## we can use an map to store all the elements or an set to store all elements and then run a loop to check if nums for 1 to n are present
## T.C -> O(n)
## S.C -> O(n)
def easy_approch(nums:list):
    my_set=set()
    m_list=list()
    for num in nums:
        my_set.add(num)
    for i in range(1,len(nums)+1):
        if i in my_set:
            pass
        else:
            m_list.append(i)
    return m_list

## an efficient soltuion 
## as we know the array should contaion 1 to n elements
## so we consider the nums as index in our array and just check that number [mark is negative]
## evry num is chcek it equivalnt index (i-1) if multiple we only chcek once
## T.C -> O(n)
## S.C -> O(1) .... o/p list not considered

def optimal(nums:list):
    m_list=list()
    for i in range(len(nums)):
        index=abs(nums[i])-1
        if (nums[index]<0):
            continue
        else:
            nums[index]*=-1
            ## we just checked every number as an index
    for i in range(len(nums)):
        if(nums[i]>0):
            m_list.append(i+1)
    return m_list
nums = [4,3,2,7,8,2,3,1]

print(easy_approch(nums))
print(optimal(nums))