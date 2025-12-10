# Given an unsorted array of integers nums, find the length of the longest consecutive elements sequence.
# You must write an algorithm that runs in O(n) time.
# Input: nums = [100, 4, 200, 1, 3, 2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
# Therefore, its length is 4.


#lets try an brute force method
# we will simply use two loops, in the first loop we wil take an element 
# in the second loop we try to find the next numbers in sequence


def brute_force(nums:list)->int:
    if(not nums):
        return 0
    longest=1
    for i in range(len(nums)):
        lt=1
        current=nums[i]
        while(nums.count(current+1)):
            current=current+1
            lt+=1
            longest=max(lt,longest)
    return longest

## now lets maybe try sorting 
## not mentioned i the question that we want to not modify the input list
## so lets sort it
## sorted() and .sort() both take T.C -> O(nlogn)
## but sorted -> S.C => O(n)

def better_approch(nums:list)->int:
    if(not nums):
        return 0
    longest=1
    nums.sort()
    # in place sort
    # T.C -> O(nlogn)
    lt=1
    for i in range(len(nums)-1):
        if(nums[i]==nums[i+1]):
            continue
            ## skipping duplicates
        if(nums[i]==nums[i+1]-1):
            lt+=1
            longest=max(longest,lt)
        else:
            lt=1
    return longest

## the above approch was O(nlogn) T.C which is better than O(n^2) brute force
## in this method we use an set to avoid duplicates and we use two nested loops 
## but the catch is its not O(n^2) as th inner loops only runs for some certain elements
## what we do is for every element we check if there is an elements before that if there is an elements before that
## that number is not start of any suquence

def optimal(nums:list)->int:
    if(not nums):
        return 0
    my_set=set()
    length=1
    for item in nums:
        my_set.add(item)
        ## average add -> O(1)
        ## for entire loop -> O(n)
    for item in my_set:
        if not(item-1) in my_set:
            count=1
            current=item
            while(item+1 in my_set):
                current+=current
                count+=1
                longest=max(longest,count)
    # the outer loops loops through all elememts T.C -> O(n)
    # if not (item-1) in my_set T.C -> O(1) 
    # From the inner loops it looks like the T.C -> O(n^2) But theres a catch
    # Looks like a nested loop, right? But here’s the trick:
    #This while loop only runs for elements that are consecutive and only for the start of a sequence.
    #Each element in the set is visited exactly once by this loop
    #after it’s counted as part of a sequence, it will never start another sequence.
    # example: 
    # my_set = {1,2,3,5,6}
    #  outer loop first sees 1 → while loop counts 2, 3 → sequence done
    # outer loop sees 2 → item-1 = 1 exists → skip (already counted)
    #  outer loop sees 3 → item-1 = 2 exists → skip
    # outer loop sees 5 → while loop counts 6
    # Gpt generated explanation:
    # Outer for loop goes through each element in the set once → O(n)
    # The if check (item-1 in my_set) runs once per element; each check is O(1) → total O(n)
    # Inner while loop looks nested, but each element is counted in only one sequence → total O(n)
    # Updating 'longest' is constant time per iteration → negligible, O(n) total
    # Overall, adding all together → O(n + n + n) = O(n), linear time


    return longest

        

            

    