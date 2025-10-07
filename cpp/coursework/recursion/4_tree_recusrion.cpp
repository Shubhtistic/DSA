// in tree recusrion a function is called multiple time instead only one time like in linear recusrion
// time complexity is O(2^n)
// space complexity -> 0(n), n+1 calls are made
#include <stdio.h>
void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);

        fun(n - 1);
        // this will also form a tree during rerurn time
    }
}
int main()
{
    fun(3);
    return 0;
}