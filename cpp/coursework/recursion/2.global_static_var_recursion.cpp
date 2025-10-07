// lets see what happens to global and static vars in recursion
#include <iostream>
using namespace std;
// global var
int global_variable = 0;
int function1(int n)
{
    if (n > 0)
    {
        global_variable++;
        return function1(n - 1) + global_variable;
        // + global variable is resolved at return time
        // so the final value of global variable will be addded to every function output
        // during return call
    }
    return 0;
}

int function2(int n)
{
    // static variable
    static int x = 0;
    if (n > 0)
    {
        x++;
        return function2(n - 1) + x;
        // +x operation is also resolved at runtime
    }
    cout << "x is " << x << endl;
    return 0;
}

int main()
{
    cout << function1(4);
    cout << "\n";
    cout << "the global var is " << global_variable << endl;
    ;
    // for function2
    cout << function2(4);
    return 0;
}