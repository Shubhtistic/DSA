
## brute force method
## quite simple we just sort the two string lexographically
## so if the strings are Anagram, they will be always equal
## the sorted function by default does sorting in lexographical order
## T.C -> O(nlogn) + O(nlogn) + O(n) we consider the largest
## T.C -> O(nlogn)
## S.C -> O(n)+O(n) = O(n)

def brute_method(s:str,t:str):
    if(len(s)!=len(t)):
        return False
        ## incase if the two strings are unequal
    s_copy=sorted(s)
    t_copy=sorted(t)
    for i in range(len(s)):
        if(s_copy[i]!=t_copy[i]):
            return False
    return True


## optimal or better approach
## in this we simply use an single dict and just count occurences in first
## then subtract same occurences in second loop 
## if all occurences are zero its an anagram


## time complexity O(n)+O(n)+O(k)= O(2n+k)= O(n), in worst case k=n
## space complexity O(k) if only alphabet letter then k=26 effectively O(1)[k=constant]
## worst case S.C -> O(n) [all leters are distinct]
def optimal_method(s:str,t:str):
    counter=dict()
    # S.c -> O(k) [worst case: O(n)]
    for alp in s:
        if alp in counter:
            # T.C -> O(n)
            counter[alp]=counter[alp]+1
        else:
            counter[alp]=1
    for alp in t:
        # T.C -> O(n)
        if alp in counter:
            counter[alp]=counter[alp]-1
            ## now subtract same occurences in second
        else:
            counter[alp]=1
    for count in counter.values():
        if count  !=0:
            return False
    return True
    
    

if(brute_method("anagram","nagaram")):
    print("Its an Anagram")
else:
    print("Not an Anagram")

if(optimal_method("anagram","nagaram")):
    print("Its an Anagram")
else:
    print("Not an Anagram")
    