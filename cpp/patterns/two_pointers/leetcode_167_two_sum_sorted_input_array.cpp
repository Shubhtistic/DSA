#include <iostream>
#include <vector>
using namespace std;

// Problem Statement
/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Return the indices of two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].*/

// Two pointer Approach
/* Unlike in normal two sum, here the array is already sorted so we know the extremes.
so we can simply start the two pointer at the extreme ends and move them according to answers to get final result */

// T.C -> O(n)
// S.C -> O(1)

vector<int> twoSum(vector<int> &numbers, int target)
{

    int i = 0;
    int j = numbers.size() - 1;

    while (i < j)
    {
        if (numbers[i] + numbers[j] == target)
        {
            return {i + 1, j + 1};
        }
        else
        {
            if (numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }

    return {};
}

int main()
{
    vector<int> a = {2, 7, 11, 15};
    int target = 9;
    auto abc = twoSum(a, target);
    for (auto a : abc)
    {
        cout << a << " ";
    }
    return 0;
}