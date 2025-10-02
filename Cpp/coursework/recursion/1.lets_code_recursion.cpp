// basic recursion example 1
#include <iostream>
using namespace std;
void function(int n)
{

    if (n > 0) // conditon for recursive call
    {
        cout << n;
        // this is printed before every call
        function(n - 1);
        // again calls the function from the start with value as n-1
    }
}
void function2(int n)
{

    if (n > 0) // conditon for recursive call
    {

        function2(n - 1);
        // again calls the function from the start with value as n-1
        cout << n;
        // this is printed in the return phase of recursion
    }
}
int main()
{

    cout << "welcome\n";
    function(5);
    // output: 54321
    cout << "\n";
    function2(5);
    // output: 12345

    return 0;
}
