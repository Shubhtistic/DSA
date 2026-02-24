// Note: The general O(n) time and O(n) space is the best approach
// But if its told to improve space then only do the two pointer approach
// or else the hashmap method is prefered
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Problem statement
/*You're given strings jewels representing the types of stones that are jewels,
and stones representing the stones you have. Each character in stones is a type of stone you have.
You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0

Constraints:
1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/

// What the question says in simple words
/*The string jewel tells which stones are jewels
and the string stones contains random stones which may contains jewels
so we have count the number of jewels in random pile of stones we have (stones string)
and letter are case sensitive so 'a' and 'A' are different*/

// Brute Force Approach
/*We will take one jewel at a time and then scan the entire stones string
and check if that jewel is present and how many times it occurs*/

// T.C -> O(n^2)
// S.C -> O(1)

int numJewelsInStones_brute(string jewels, string stones)
{
    int c = 0;
    for (int i = 0; i < jewels.size(); i++)
    {
        char test = jewels[i];

        for (int j = 0; j < stones.size(); j++)
        {
            if (stones[j] == test)
            {
                c++;
            }
        }
    }

    return c;
}

// Standard Optimal Approach
/* we will make a set of jewels and then we will use that set for lookup
we will run a simple loop in which for every element we check againt the set if that element is a jewel
if yes we increase the counter otherwise go ahead and repeat until loop finishes*/

// T.C -> O(n)
// S.C -> O(n)

int numJewelsInStones_optimal1(string jewels, string stones)
{
    unordered_set<char> st(jewels.begin(), jewels.end());
    int c = 0;

    for (auto item : stones)
    {
        if (st.find(item) != st.end())
        {
            c++;
        }
    }
    return c;
}

// Two Pointer Approach
/*Please Read the note at the start of the question
What we can do is follow the two pointer pattern and then sort both the jewel and stone
what it will do is we can easily now compare both as they will be ordered
we compare and if we get jewels we then simply count how many are there is stones
also count becomes easy as all elements are now in order
*/

int numJewelsInStones_optiimal2(string jewels, string stones)
{
    sort(jewels.begin(), jewels.end());
    sort(stones.begin(), stones.end());
    int i = 0;
    int j = 0;
    int c = 0;

    while (i < jewels.size() and j < stones.size())
    {

        if (jewels[i] == stones[j])
        {
            while (j < stones.size() and jewels[i] == stones[j])
            {
                c++;
                j++;
            }
        }
        else
        {
            if (jewels[i] > stones[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    return c;
}

int main()
{

    return 0;
}