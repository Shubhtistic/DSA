#include <iostream>
using namespace std;
int factorial(int limit)
{
    if (limit == 0)
    {
        return 1;
    }
    return limit * factorial(limit - 1);
}
int main()
{
    int limit = 5;

    cout << "Using Recursive method: " << factorial(limit);
    cout << "\n-------------------------------------------------\n";
    cout << "Using loop (iteration): ";
    int result = 1;
    for (int i = limit; i >= 1; --i)
    {
        if (i == 0)
        {
            result = 1;
        }
        result = result * i;
    }
    cout << result << endl;
    return 0;
}