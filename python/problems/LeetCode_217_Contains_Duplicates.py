## lets try an brute force force approach
## siimply use two loops to compare one variable at a time to other
## if one var is present more than once -> contains duplicates
## T.C -> O(n^2)
## S.C -> O(1)


def brute_force(nums:list)-> bool:
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):
            if(nums[i]==nums[j]):
                return True
    return False



## another optimal approch is using an set 
# set only stores unique elements
## is at the end both set and given list have same length it means, they all are distinct

def optimal_approach1(nums:list)-> bool:
    my_dict=dict()
    for item in nums:
        my_dict[item]=my_dict.get(item,0)+1
        if( my_dict[item]>1):
            return True
    return False
        
def optimal_approach2(nums:list)-> bool:
    my_set=set()
    for item in nums:
        if item not in my_set:
            my_set.add(item)
    
    if (len(nums)==len(my_set)):
        return False
    else:
        return True

list1=[1,1,2,3,4,5]
if(brute_force(list1)):
    print("contains duplicates")

if(optimal_approach1(list1)):
    print("comtaisn duplicates")

if(optimal_approach2(list1)):
    print("comtaisn duplicates")


    