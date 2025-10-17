
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

/*
We have a bunch of strings, and we want to group all the words that are anagrams of each other.
An anagram just means the letters are the same, maybe in a different order.

Ex:
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
 if we sort all the letters the anagrams will be identical

what we will do is we will make an set which holds all the indexes of  the words are to be grouped
i.e the anagram
by using set we can store an count as well avoid duplicates

T.C:
sorting words -> n words and each sort takes nlogn => O(n*klogk) ... n and k are diff
nested loop for comparison -> O(n^2)
Set insert/check: O(log n) each -> tiny compared to the big O(n² * k)
- Total ≈ O(n²)

S.C:
Copy vector: O(n)
Set: O(n)
Output vector: O(n)
Total ~ O(n + total length of strings)

*/

vector<vector<string>> brute_force(vector<string> &strs)
{
    // make a copy of strs
    auto copy = strs;
    // s.c -> O(n)
    for (auto &item : copy)
    {
        sort(item.begin(), item.end());
        // sort each word of the vector of strings
    }
    // T.C -> O(n*klogk)

    // output vector and a set to track what we’ve already grouped
    vector<vector<string>> op_vec; // this will hold the final groups
    set<int> grouped;              // keeps track of which indices we’ve used

    // iterate through each word by index
    for (int i = 0; i < copy.size(); i++)
    {
        if (grouped.count(i))
            continue;
        // check if set already has that index

        vector<string> temp;
        // temp vector to hold group for each iteration

        temp.push_back(strs[i]);
        // add the original word and not sorted
        grouped.insert(i);
        // mark it as grouped

        // check all words one by one
        // use i+1 to avoid copies
        for (int j = i + 1; j < copy.size(); j++)
        {
            // if letters match and we haven’t grouped it yet
            if (copy[i] == copy[j])
            {
                if (!grouped.count(j))
                {
                    temp.push_back(strs[j]); // add it to current group
                    grouped.insert(j);       // mark it as grouped
                }
            }
        }

        op_vec.push_back(temp);
        // push the formed group for current iteration
        // may contain one strimg or multiple strings
    }

    return op_vec;
}

/*
lets try to do a optimal solution
we can use an map which has "key" the sorted word and "value" a vector which has all grouped original strings
what we do simply is sort an word and and push the original word
// if sorted word already exists the original word is appended into that unique key


T.C -> O(n*klogk)
S.C -> O(n*k) .... n strings × k characters each = O(n * k)

*/

vector<vector<string>> optimal(vector<string> &strs)
{

    // Step 1: create unordered_map to group words by their sorted version
    unordered_map<string, vector<string>> mp;
    // Each string has k characters.
    // You have n strings.
    // Total S.C -> O(n*k)
    for (auto &word : strs)
    {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        // sort the word the key stays unique

        mp[sortedWord].push_back(word);
        // push back the original word into the value vector
    }
    // T.C -> O(n*klogk)

    // collect the groups from the map into a vector of vectors
    vector<vector<string>> result;
    for (auto &p : mp)
    {
        result.push_back(p.second); // push each group
    }

    // Step 3: done! return the grouped anagrams
    return result;
}

int main()
{
    vector<string> test = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = brute_force(test);
    vector<vector<string>> result_optimal = optimal(test);

    for (auto &group : result)
    {
        // group is a vector<string>
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl; // new line for each group
    }

    for (auto &group : result_optimal)
    {
        // group is a vector<string>
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl; // new line for each group
    }

    return 0;
}