#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// Given an unsorted array of integers nums, find the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
/*Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore, its length is 4.
*/

// lets try an brute force approach
// in this brute force approch we will simply first make an map which store all the elements in the map
// then we will use two loops
// first loop runs for all elements of given array
// second loop has no end condition it simply works on the conditional statements inside
// we start the second loop from 1 and always we will check in suquence
// if nums+1 then counter++ , if nums+2 then counter++ and so on if we dont find match we simply break inner loop and value of i increments and we check for new element

// T.C -> O(n^2)
// S.c -> O(n)

int brute_force(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
        // empty array
    }
    unordered_map<int, int> mapp;
    for (auto item : nums)
    {
        mapp[item] += 1;
    }
    // S.C -> O(n)
    vector<int> subs;

    for (int i = 0; i < nums.size(); i++)
    {
        int counter = 1; // an single element counted as subsequence
        for (int j = 1; j; j++)
        {
            if (mapp.find(nums[i] + j) != mapp.end())
            {
                counter++;
            }
            else
            {
                break;
                // critcal condition
            }
        }
        subs.push_back(counter);
        // for every suquence push back its counter
    }
    int mx = 0;
    for (const auto item : subs)
    {
        mx = max(mx, item);
    }
    return mx;
}

// do we need an hash map in the force method
// lets try a solution without extra space
// T.C -> O(n^2)
// S.C -> O(1)

int brute_force2(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
        // empty array
    }
    int longest = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int count = 1;
        while (find(nums.begin(), nums.end(), x + 1) != nums.end())
        {
            x++;
            count++;
        }

        longest = max(longest, count);
    }
    return longest;
}

// now how to optimize
// should we try sorting
// T.C -> O(nlogn)
// S.C -> O(1)
// this version will pass the leetcode submission
// finally done -_-

int better_method(vector<int> nums)
{
    if (nums.empty())
    {
        return 0;
        // empty array
    }
    sort(nums.begin(), nums.end());
    // in place sort of the nums copy
    int count = 1;
    int largest = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            continue;
        // very imp skip dupliactes

        if (nums[i] == nums[i + 1] - 1)
        {
            count++;
            largest = max(largest, count);
        }
        else
        {
            count = 1;
        }
    }
    return largest;
}

// now we need to get an optimal solution which has T.C as O(n)
// how about we make an set and find for elements in a single check
// lets try an set as the array ccan contaion dupliacte elements also
// the hack is for every element we find if there is an element before it if it exists its not the starting point for that sequence

// IMP: for unordered set the O(1) for finding in very rare cases it can be O(n) if collisions occur
// so the code assumes hash function distributes elements uniformly
// means no too many collisions in buckets -> then avg case O(1) lookup holds
// hence total T.C => O(n) for inserting + O(n) for finding = O(2n) ≈ O(n)
// if collision happens badly then lookup becomes O(n) making overall O(n^2)
// S.C = O(n) as we store all unique elements in set

int optimal_method(vector<int> &nums)
{
    // we start with assuming the longest sequence length as 1 by default
    int longest = 1;

    // we make an unordered set bcz we want O(1) avg time for finding any element
    unordered_set<int> st;

    // now we push all elements from nums into our set
    // duplicates will automatically get ignored as set only stores unique values
    for (auto item : nums)
    {
        st.insert(item);
    }

    // now we will iterate over each element of our set one by one
    // now this is our main loop which goes through every element in the set once
    // so the outer for loop itself runs O(n) times bcz set has all unique elements only
    // inside this we first do st.find(it-1) which is O(1) avg case (unordered_set lookup)
    // so till now => O(n) * O(1) = O(n)

    // now if the current element is the starting point of a sequence we enter the while loop
    // inside while -> we keep checking st.find(x+1), st.find(x+2), ... until numbers break
    // each element can only be checked at most once as part of some sequence
    // means all these while loop checks across full program total up to another O(n)

    // so we have 3 main passes across data:
    // inserting into set = O(n)
    // main for loop with find(it-1) checks = O(n)
    // inner while loop checking next consecutive numbers = O(n)
    // total ≈ O(3n) → which simplifies to O(n) overall

    // but remember this O(1) lookup assumption holds only if no heavy hash collisions
    // otherwise in worst case it breaks and becomes O(n^2)

    for (auto it : st)
    {
        // if we don’t find element just before it (it-1), means this can be the start of a sequence
        if (st.find(it - 1) == st.end())
        {
            int count = 1; // to count length of that sequence
            int x = it;    // start from this number

            // now we will keep checking for next consecutive numbers like x+1, x+2, ...
            // if we find them we increase count and move ahead
            while (st.find(x + 1) != st.end())
            {
                x = x + 1; // move to next consecutive element
                count++;   // increase the sequence count
            }

            // after finishing one full sequence, we compare its length with longest so far
            longest = max(longest, count);
        }
    }

    // finally return the maximum length of consecutive sequence found
    return longest;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                        19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
                        35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 67, 89, -987, 0, 0, 89, 9,
                        46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
                        62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
                        77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92,
                        93, 94, 9, 96, 97, 98, 99, 100, 101, 102, 103, 104, 98, 76, 56, 30,
                        105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117,
                        118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134};

    cout << brute_force(nums) << endl;
    cout << brute_force2(nums) << endl;
    cout << better_method(nums) << endl;
    cout << optimal_method(nums) << endl;
    return 0;
}
