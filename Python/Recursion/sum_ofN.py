#trying to find sum of fist n natural numbers using recursion in python
def sum_ofN(nth_term):
    if(nth_term==0):
        return 0
    return sum_ofN(nth_term-1)+nth_term
    ## the part nth term will be resolved in return time
print(sum_ofN(4))