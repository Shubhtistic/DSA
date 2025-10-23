#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// in this we simply want to return the number of subarray sums that add upto an guevn k element

// lets try an brute force approch for this
// we try each subarray at a time to check for all possible arrays matching k
//  T.C -> O(n^2)
//  S.C -> O(1)

int brute_force(vector<int> &nums, int k)
{
    int count = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        int sum = 0;
        for (int j = i; j < len; j++)
        {
            {
                sum = sum + nums[j];

                if (sum == k)
                {
                    count++;
                    // just see if any subarray equals k and keep updating for next subarrays also
                    // first subbaray sums from 0 to len-1
                    // then from 1 to len-1
                    // then from 2 to len-1
                    // and continued
                }
            }
        }
    }

    return count;
}

// lets try an optimal solution
// in this method we will use an hash map and prefix sum pattern
// T.C -> O(n)
// S.C -> O(n)

// --------------------------------- OPTIAL -----------------------------------------
/*
==========================================================================================
🧠 1. The Core Problem
------------------------------------------------------------------------------------------
We need to count the number of *continuous subarrays* whose sum = k.

Example:
nums = [1, 2, 3], k = 3
Subarrays that sum to 3 → [1,2], [3] → Total = 2
==========================================================================================


🧩 2. Naïve Thinking
------------------------------------------------------------------------------------------
- Brute force way: compute every subarray sum → O(n²)
- But we want an optimized O(n) approach.
- That’s where **Prefix Sum** + **HashMap** come in.
==========================================================================================


🔍 3. The Prefix Sum Concept
------------------------------------------------------------------------------------------
Let’s define prefix sum:

    pfx[i] = sum of nums[0..i]

That means:
    pfx[0] = nums[0]
    pfx[i] = pfx[i-1] + nums[i]

💡 Key Idea:
    Sum of subarray nums[l..r] = pfx[r] - pfx[l-1]
==========================================================================================


🧮 4. Reformulating the Problem
------------------------------------------------------------------------------------------
We need subarrays where:
    pfx[r] - pfx[l-1] = k
→  pfx[l-1] = pfx[r] - k

So for each prefix sum pfx[r],
we just need to know **how many previous prefix sums** had the value (pfx[r] - k).
==========================================================================================


🧱 5. Role of the HashMap
------------------------------------------------------------------------------------------
unordered_map<int,int> mp;  // stores prefix_sum → frequency

For every new prefix sum pfx[i]:
    1. Check if (pfx[i] - k) exists in the map.
    2. If yes → all those occurrences form valid subarrays ending at i.
    3. Then add pfx[i] itself to the map for future use.
==========================================================================================


🏁 6. Why Initialize mp[0] = 1
------------------------------------------------------------------------------------------
Before forming any prefix, the “sum = 0” is a valid baseline.
It allows subarrays starting at index 0 to be counted.

Example:
nums = [3, 4, 5], k = 3
prefix[0] = 3 → pfx[0] - k = 0
If mp[0] = 1, we correctly count subarray [0..0] (sum = 3).

If we don’t initialize mp[0] = 1, we miss subarrays starting from the beginning.
==========================================================================================


💡 7. Why the Comment “we don’t fill map first” is ❌ Wrong
------------------------------------------------------------------------------------------
✖ Incorrect: “we don’t fill map first or it breaks the sequence”
✔ Correct: We **must** start with mp[0] = 1.

This doesn’t break anything — it enables subarrays beginning from index 0.
Without it, you’ll still count later subarrays correctly, but miss those starting at 0.
==========================================================================================


⚙️ 8. Step-by-Step Example (Real Reasoning)
------------------------------------------------------------------------------------------
nums = [3, 4, 5, 6, 7], k = 7

┌─────┬───────────────┬─────────┬──────────────────────────────┬────────┐
│  i  │ cumulativeSum │ needed  │ map_before                  │ count  │
├─────┼───────────────┼─────────┼──────────────────────────────┼────────┤
│  0  │ 3             │ -4      │ {0:1}                       │ 0      │
│     │ → add 3:1     │         │                              │        │
│  1  │ 7             │ 0       │ {0:1,3:1}                   │ +1 (0) │
│     │ → add 7:1     │         │                              │        │
│  2  │ 12            │ 5       │ {0:1,3:1,7:1}               │ 0      │
│     │ → add 12:1    │         │                              │        │
│  3  │ 18            │ 11      │ {0:1,3:1,7:1,12:1}          │ 0      │
│     │ → add 18:1    │         │                              │        │
│  4  │ 25            │ 18      │ {0:1,3:1,7:1,12:1,18:1}      │ +1 (18)│
└─────┴───────────────┴─────────┴──────────────────────────────┴────────┘

✅ Total subarrays with sum = 7 → 2
==========================================================================================


📚 9. How to *Really* Internalize It
------------------------------------------------------------------------------------------
Visualize 3 running variables in the loop:

┌──────────┬──────────────────────────────────────────────┐
│ Variable │ Meaning                                      │
├──────────┼──────────────────────────────────────────────┤
│ sum      │ cumulative prefix sum up to i                │
│ sum - k  │ prefix sum value we want to have seen before │
│ mp       │ frequency of all prefix sums seen so far     │
└──────────┴──────────────────────────────────────────────┘

💭 Think like this:
"I'm walking through the array, building a running total.
If I've seen a previous total that was exactly k less than my current,
that means between that point and now, the sum is exactly k."
==========================================================================================


✅ 10. Correct Summary Comment (You Can Use This in Code)
------------------------------------------------------------------------------------------
unordered_map<int,int> mp;
// mp stores prefix_sum → count of how many times it has appeared
// Initialize mp[0] = 1 to handle subarrays starting from index 0
// While iterating through nums:
//   1. Keep a running prefix sum.
//   2. If (prefix_sum - k) exists in mp, all its occurrences form valid subarrays.
//   3. Increment count by mp[prefix_sum - k].
//   4. Record current prefix_sum in mp for future use.
==========================================================================================


🧠 11. Key Concept Links to Remember
------------------------------------------------------------------------------------------
┌────────────────────────────┬──────────────────────────────────────────────────────────┐
│ Concept                    │ Used For                                                 │
├────────────────────────────┼──────────────────────────────────────────────────────────┤
│ Prefix Sum                 │ Reduces subarray sum computation to O(1)                 │
│ HashMap (prefix → count)   │ Efficiently tracks how many prefix sums occurred         │
│ Cumulative Reasoning       │ Turns subarray problems into running-state problems      │
│ Initialization mp[0] = 1   │ Ensures subarrays starting at index 0 are counted        │
└────────────────────────────┴──────────────────────────────────────────────────────────┘
==========================================================================================


🔑 Mental Shortcut
------------------------------------------------------------------------------------------
"Every prefix sum remembers all subarrays that ended before it.
When you see a new sum, just ask —
   has there ever been a prefix sum that was k less than now?
If yes, those subarrays close the gap to form exactly k."

That’s how you **truly grasp** the concept — intuitively, not by memorization.
==========================================================================================
*/

int optimal(vector<int> &nums, int k)
{
    vector<int> pfx(nums.size());
    int count = 0;
    pfx[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        pfx[i] = pfx[i - 1] + nums[i];
    }
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (pfx[i] == k)
        {
            count++;
        }
        int val = pfx[i] - k;
        if (mp.find(val) != mp.end())
        {
            count = count + mp[val];
        }
        if (mp.find(val) == mp.end())
        {
            mp[val] = 0;
        }
        mp[pfx[i]]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    cout << brute_force(nums, 2) << endl;
    cout << optimal(nums, 2) << endl;

    return 0;
}