#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Problem Statement
/*Given a string ‘N’ that represents a number,
you need to check if the given number is a strobogrammatic number or not.
A strobogrammatic number is a number that looks the same when rotated by 180.
In other words, a number that on rotating right side up and upside down appears the same is a strobogrammatic number.
For Example:
‘986’ is a strobogrammatic number because on rotating ‘986’ by 180, ‘986’ will be obtained.
*/

// Simple Approach or Brute Approach
/*So from above we can say that the numbers 0,1,6,8,9 are strobogrammatic
so if any other number than these come up it then rejected at that moment
so what we can do is run a simple loop which converts the numbers into their proper strobogrammatic form
and directly rejects other numbers also
the we reverse and check if they are same*/

// T.C-> O(n)
// S.C -> O(n)

bool simple_approach(string &n)
{
    string n1 = n;

    for (int i = 0; i < n.size(); i++)
    {
        if (n1[i] == '6')
        {
            n1[i] = '9';
        }
        else if (n1[i] == '9')
        {
            n1[i] = '6';
        }
        else if (n[i] == '0' or n[i] == '8' or n[i] == '1')
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    int k = 0;
    int j = n.size() - 1;
    while (k <= j)
    {
        swap(n1[k], n1[j]);
        k++;
        j--;
    }
    if (n1 == n)
    {
        return true;
    }

    return false;
}

// Optimal Two Pointer Approach

/*Its very easy once you understand, what we will do is we use two pointers at extreme ends
we will compare one by one , if the numbers are 6 and 9 then we will check its strobogrammatic number at other pointer
if does not exist we just return false at that moment, if numbers are 1,0 and 8 we wheck if other pointer has same value
we just move both pointers in such case and if we encounter non-strobogrammatic number we return false at that moment*/

// T.C -> O(n)
// S.C -> O(1)

bool optimal(string &n)
{
    int i = 0;
    int j = n.size() - 1;

    while (i <= j)
    {
        if (n[i] == '9')
        {
            if (n[j] != '6')
            {
                return false;
            }
            i++;
            j--;
        }
        else if (n[i] == '6')
        {
            if (n[j] != '9')
            {
                return false;
            }
            i++;
            j--;
        }
        else if (n[i] == '0' or n[i] == '8' or n[i] == '1')
        {
            if (n[i] != n[j])
            {
                return false;
            }
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "123456";
    string s1 = "986";
    if (simple_approach(s))
    {
        cout << "Strobogramatic " << s << endl;
    }
    else
    {
        cout << "Not Strobogrammatic" << endl;
    }
    if (optimal(s))
    {
        cout << "Strobogramatic " << s << endl;
    }
    else
    {
        cout << "Not Strobogrammatic" << endl;
    }

    cout << "=============================================================" << endl;
    cout << "Using optimal" << endl;
    if (simple_approach(s1))
    {
        cout << "Strobogramatic " << s1 << endl;
    }
    else
    {
        cout << "Not Strobogrammatic" << endl;
    }
    if (optimal(s1))
    {
        cout << "Strobogramatic " << s1 << endl;
    }
    else
    {
        cout << "Not Strobogrammatic" << endl;
    }
    return 0;
}