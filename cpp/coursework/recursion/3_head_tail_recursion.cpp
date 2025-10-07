// types of recursion: tail,head,tree,indirect,nested and linear
// lets look at tail and head
#include <iostream>
using namespace std;

void tail(int n)
{
    // in tail recursive call is at the end of the function
    if (n > 0)
    {
        cout << n;
        tail(n - 1);
    }
}

void head(int n)
{
    // in head recursive call is at the start of the function
    if (n > 0)
    {
        head(n - 1);
        cout << n;
    }
}
int main()
{
    tail(4);
    // 4321
    cout << "\n";
    head(4);
    // 1234

    // always prefer loops over head and tail
    // head and tail -> space and time both = O(n)
    // a simple loop time -> O(n) and space -> O(1)
    return 0;
}