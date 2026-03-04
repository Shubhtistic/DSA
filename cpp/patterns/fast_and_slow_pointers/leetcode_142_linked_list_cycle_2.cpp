#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Problem Statement
/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that the tail's next pointer is connected to (0-indexed).
It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where the tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where the tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:
The number of nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked list.*/

// Easy Approach
/*An easy approach would be using a hash set to store each node's address.
Once we enter the loop and when we are about to reach the end of the loop,
we will again visit the node where the loop started.
i.e., the loop starts again with that node, so once we find that using the set we can simply return it.*/

// T.C -> O(n)
// S.C -> O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *detectCycle_easy(ListNode *head)
{
    unordered_set<ListNode *> st;
    ListNode *fast = head;
    while (fast != nullptr)
    {
        if (st.find(fast) != st.end())
        {
            return fast;
        }
        st.insert(fast);
        fast = fast->next;
    }

    return nullptr;
}

// Optimal Approach
/*This will take time at first to understand.
What we will do is simply reach the point at which fast and slow meet.
From that point start fast at head again.
After that move both at just one step at a time and the point they meet will be exactly the start of the loop.
We can better understand this using the mathematical proof.

[]--[]--[]--[ x ]--[]--[s==f]
             ||          ||
             []----[]----[]

Above is a simple ASCII linked list I drew [ I tried my best :) ].
The node marked as x denotes the start of the loop.
Let's assume the distance from the starting node to node 'x' is X,
and from node x till the point at which both meet that distance is 'Y' [marked as 's==f' in the above diagram].
And let's assume the entire loop is of length L.
So the remaining part, i.e., from the point at which both pointers meet till the node 'x' again which completes the loop,
let that distance be simply L-Y (as L is the total length of the loop).

N1 -> total rotations by slow
N2 -> total rotations by fast

So let's do the equation now.

slow == fast -> X + N1L + Y == 2(X + N2L + Y) .... fast pointer is twice as fast as slow so it always covers double the distance in the same time.

N1L = X + Y + 2(N2L)

[N1 - 2(N2)] L = X + Y

Let's assume [N1 - 2(N2)] as some constant k.

Lk - Y = X

if k = 1
L - Y = X

if k = 2 ... it won't change the logic, just more rotations.

2L - Y = X

So this proves after fast and slow meet, reset fast to head and move both at normal speed.
The moment they meet it is the start of the loop.
*/

// T.C -> O(n)
// S.C -> O(1)

ListNode *detectCycle(ListNode *head)
{

    ListNode *fast = head;
    ListNode *slow = head;

    // detect if cycle is there
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            break;
        }
    }

    // very imp step -> check if it is actually null
    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }

    // find the start now
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

int main()
{

    return 0;
}