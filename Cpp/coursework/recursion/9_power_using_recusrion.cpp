#include <iostream>
using namespace std;
int power_(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return power_(base, power - 1) * base;
}
int main()
{
    int base = 2;
    int power = 3;

    cout << "Using Recursion: " << power_(base, power) << endl;
    cout << "-----------------------------------------------------------\n";
    cout << "Using loop: ";
    int result = 1;
    for (int i = 1; i <= power; i++)
    {
        result = result * base;
    }
    cout << result << endl;
    return 0;
}