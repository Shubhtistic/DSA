#include <iostream>
using namespace std;
int function(int nTH_term)
{
    if (nTH_term == 0)
    {
        return 0;
    }
    return function(nTH_term - 1) + nTH_term;
}
int main()
{
    cout << "The Output with Recursive function " << function(6) << endl;
    cout << "----------------------------------------------------------\n";
    cout << "The output with Normal Loop(Iterative methhod): ";
    int sum = 0;
    for (int i = 0; i <= 6; ++i)
    {
        sum = sum + i;
    }
    cout << sum << endl;

    return 0;
}