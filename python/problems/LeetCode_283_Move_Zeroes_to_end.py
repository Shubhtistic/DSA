## in this this we are given an array which has zeros and non zeros 
## we simply have to move all zeros the end while keeping the relative order same
## example=[0,1,0,3,12]
## Output: [1,3,12,0,0]
## 1,3,12 are in thier relative order 

## easy approch 
## we can make two arrays to store the zeros and non zeros and at last mix it with the original array
## we can optimize this by removing the zero array as we dont need it we only modify te original array with non zeros and then fill remaining with zeros
## T.C -> O(n)
## S.C -> O(n) 


def easy_method(nums:list)->list:
    
    n_list=list()
    for num in nums:
        if(num!=0):
            n_list.append(num)
        
    for i in range(len(nums)):

        if(i>len(n_list)-1):
            nums[i]=0
        else:
            nums[i]=n_list[i]
        
    return nums


## in the above method we needed an extra array to store the non zero elements
## but what if we do it withouf the extra array
## we can just modify the existing array by filling it non zero elements and when all are placed in order fill out remaining with zeros
## T.C -> 0(n)
## S.C -> O(1)

def optimal_approch(nums:list)->list:
    current_index=0
    ## to keep track
    for i in range(len(nums)):
        if(nums[i]!=0):
            nums[current_index]=nums[i]
            current_index=current_index+1
    for i in range(current_index,len(nums)):
        nums[i]=0
    return nums


example=[0,1,0,3,12]
print(easy_method(example))
print(optimal_approch(example))