#include <iostream>
#include <unordered_set>
using namespace std;

// Problem Statement
/*Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number with the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true

Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1*/

// Easy Approach
/*What the problem basically says is we have to start with a +ve number and find the sum of squares.
We have to repeat this exact process until the sum of squares at some stage becomes 1. If it is 1, then it is a happy number.
So we have to repeat something, that much we know. But at what condition should we stop? If we don’t, then it will become an infinite loop.
So what can happen is as we keep iterating, at some time the number is going to repeat its old sums as it is a mathematical property.
So what we can do is store the sums in a set or map, and every time we find a sum we can check if our set/map contains that.
If the map contains the sum, then we can say that it is in a loop and we break at that moment.*/

// T.C -> O(n)
// S.C -> O(n)

int sm(int num)
{
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        sum = sum + (digit * digit);
        num = num / 10;
    }
    return sum;
}

bool isHappy_simple(int n)
{
    unordered_set<int> st;
    int current = n;

    while (true)
    {
        int sum = sm(current);

        if (sum == 1)
        {
            return true;
        }
        else if (st.find(sum) != st.end())
        {
            /// found
            return false;
        }
        else
        {
            st.insert(sum);
        }

        current = sum;
        // new number
    }

    return false;
}

// Optimal Approach
/*If you read the simple approach, what did we focus on? Finding the sum of squares of digits in a repetitive manner,
following the same approach for multiple numbers in multiple iterations, and if a number repeats we were stuck in a loop.
Does that resemble something? Fast and slow pointers -> finding something in cycles or repetitive manner.
What we can do is the fast pointer finds the sum of squares of digits of the number twice, and slow finds it once.
We will follow this for many iterations, and if at some point slow == fast, then we are in a loop and we break.*/

// T.C -> O(n)
// S.C -> O(1)

bool isHappy_optimal(int n)
{
    int slow = n;
    int fast = n;

    while (true)
    {
        fast = sm(sm(fast));
        // run two times for fast
        slow = sm(slow);

        if (fast == 1)
        {
            return true;
        }
        else if (slow == fast)
        {
            return false;
        }
    }
}

int main()
{
    return 0;
}