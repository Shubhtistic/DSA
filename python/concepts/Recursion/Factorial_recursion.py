## lets try to find factorial using recursion and loop method also
def fact_by_rec(num):
    if(num==0):
        return 1
    return fact_by_rec(num-1)*num
    ## num is resolved in return part
    