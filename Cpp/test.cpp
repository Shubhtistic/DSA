

#include <iostream>
using namespace std;
void function(int a, int b, int count = 0)
{
    cout << a + b;
    if (count < 3)
    {
        function(a, b, count + 1);
    }
}
int main()
{
    cout << "testing\n";
    function(2, 4);
    return 0;
}