## brute force method
## run two loops to check indexes
## T.C -> O(n^2)
## S.C O(1)

def brute_force( nums:list, target: int):
        small=0
        large=0
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)):
                ## i+1 is reason this brute force method a bit efficient we dont check backawards
                if(i==j):
                    continue
                elif(nums[i]+nums[j]==target):
                        small=i
                        large=j
                        break
                        # small=min(i,j)
                        # large=max(i,j)
                        ## i should be the smaller by default
        return [small,large]

## lets try an hashmap method
## we simply do like for example 8 + _ =14 so we just find if the 14-8 elements is present in hashmap(diict in python)
## T.C -> O(n)(in c++ maps -> O(nlogn) & unordered_sets -> O(n))
## S.C -> O(n)
def better_approach(nums:list,target:int):
    my_dict=dict()
    for i in range(len(nums)):
          complement=target-nums[i]
          if complement in my_dict:
                return [my_dict[complement],i] # indexes
          my_dict[nums[i]] = i
          

    
nums=[2,7,11,15]
print(brute_force(nums,9))
print(better_approach(nums,9))


## note: there is an two sum II problem on leetcode
# it is already sorted so can we directly use two pointers approach on it 
