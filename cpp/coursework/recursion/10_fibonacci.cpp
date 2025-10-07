#include <iostream>
using namespace std;
// lets try to find the nth term using recursion
int fibonacci(int term_number)
{
    // for fibonacci 0th term =1
    // 1st term =1
    // 2nd = 0+1
    // and so on
    if (term_number == 1 or term_number == 0)
    {
        return 1;
        // handling edge case
    }
    else
        return fibonacci(term_number - 2) + fibonacci(term_number - 1);
}

// lets try to print fiboannci term using an loop
void print_fibonacci(int n)
{
    if (n == 0 or n == 1)
    {
        cout << 1 << " ";
    }
    for (int i = 2; i <= n; i++)
    {
        cout << (i - 1) + (i - 2) << " ";
    }
}
int main()
{
    int term = 5;

    cout << "Finding nth term using recursion: " << fibonacci(term) << endl;
    cout << "--------------------------------------------------------\nPrinting n terms of fibaonaci sequence\n";
    print_fibonacci(term);

    return 0;
}