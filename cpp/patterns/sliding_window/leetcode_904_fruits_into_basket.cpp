#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

// Problem Statement
/*You are visiting a farm that has a single row of fruit trees arranged from left to right.
The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.


Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].*/

// What the problem
/*The problem in simple words says that we have a farm and there are multiple trees
and each unique corresponds to fruit of a specific tree
just for example assume
arr=[1,2,3,1,1]
1 -> apple
2 -> pear
3 -> guava
1 -> again apple
1 -> another apple again
And the second thing the question states is that we are only limited to two types of fruit in our bucket
so we have the two fruits which are most in farm*/

// How to solve
/*If you properly read this, we can treat the tree as a continous array with multiple values
and we have a part of array which has the most count of 2 distinct numbers [ most fruits in the farm on only two types]
so if you try to think -> this is an subarray question, finding longest subarray with 2 distinct numbers (instead of k nunbers)
So basically find biggest subarray where are there are two distinct numbers and count is highest in the array
Or in simple Words -> Fill two buckets with distinct fruits which occur in farm the most*/

// Similar Question
/*We did the question longest substring with distinct k uniques
this question 99.9% same as that, the 0.1 just for fruits :)
Take a look at that question if you do that this question will feel like a repetition of that question*/

// Sliding Window Approach
/*We start the low and high both at 0 as this is an dyamic window
We also keep a hashmap to store the fruits and their counts
WE keep increasing high on every iteration as it will store the fruit in hashmap along with its frequency
after that once we reach size of 2 i.e two buckets filled with distinct fruits
we count size of that subarray (how many trees we covered left to righ to fill those buckets)
if we exceed that size i.e a new fruit added we check can we remove the fruits we added in start and fill this to see if
these new fruits are more in size i.e remove starting frits and decrease their frequncy in map and once they are zero remove the
so one a fruit is removed another one is added we then see with this fruit does the number of fruits increase or not*/

// T.C -> O(n)
// S.C -> O(1)
int totalFruit(vector<int> &fruits)
{

    int low = 0;
    int mxm = INT_MIN;
    unordered_map<int, int> mp;

    for (int high = 0; high < fruits.size(); high++)
    {

        mp[fruits[high]]++;

        while (mp.size() > 2)
        {

            mp[fruits[low]]--;
            if (mp[fruits[low]] == 0)
            {
                mp.erase(fruits[low]);
            }
            low++;
        }

        if (mp.size() <= 2)
        // we do mp.size() <=2, because may contaion only one fruit which is repeated multiple times
        {
            mxm = max(high - low + 1, mxm);
        }
    }
    return mxm;
}

int main()
{

    return 0;
}