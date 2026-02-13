#include <iostream>
#include <unordered_set>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;

// Problem Statement
/*Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again
by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.


Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false*/

// What the question states
/*The question asks us to find if the given linked lkst has a loop or not
by loop its means unlike a normal straight linked list which would end at a node,
A Linked list with loop or cycle does not end but it wraps around itself at some node and keep on moving in a loop
So we have to tell if the given linked list has a cycle or not i.e does it end or it is stuck in a loop(cycle)*/

// simple Appraoch
/*IN this simple approach what we can do is we just store the address of each node of linked list in a hash map or a set
We will prefer set as we only want to store the adress and we dont have to do anything with their counts so we save some
extra space by removing int overhead of hashmap.
And then  we check, for every new node if the address is already present in the 'set' -> if it present we can say that
we already visited this node and therefore this linked list is in a loop.
and if we reach end of linked list without finding any duplicate nodes it means the linked list is not in cycle*/

// T.C -> O(n)
// S.C -> O(n)

bool hasCycle_simple(ListNode *head)
{

    unordered_set<ListNode *> st;

    ListNode *temp = head;
    while (temp != NULL)
    {
        if (st.find(temp) == st.end())
        {
            // this node is new and not duplicate
            st.insert(temp);
        }
        else if (st.find(temp) != st.end())
        {
            // already present -> duplicate Node
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Optimal Fast-slow ptr Approach
/*So according to Fast-Slow ptr approach we move slow ptr once and fast ptr multiple times
we can utilize this, what we can do is we will start both slow and fast and
if the list is in loop then fast and slow ptrs are bound to meet. We wil try to understand this using real world example

Real World Example:
lets assume two friends want to race just for fun

1st Scenario -> Straight Road
lets assume both friend start at same place(initially slow and fast both at 0)
but friend 1 (fast ptr) is faster than friend 2(slow ptr)
So after running Running for some time friend 1 (fast ptr) is going to be always ahead and they cant meet each other
and friend 1 will reach finish line first
So the road was straight and faster one reached the end first and they never crossed each other during
Corresponds to fast ptr reaching the end in linked list while slow always stays behind -> no loop linked list

2nd Scenario -> running ground(circular)
In this even though friend 1(fast ptr) is faster and friend 2(slow ptr) is slow but both are bound to meet at some time
Beacuse friend 1 will continue his slow run but friend 1 who is faster at some time will overtake him
Coresponds to finding loop in linked list */

// T.C -> O(n)
// S.C -> O(1)

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        // VERY IMP!!
        // this edge case is very imp
        // (fast->next != NULL)
        // what if after moving 1 node fast ptr was already Null
        // we cant blindly make it jump two nodes
        // would result in runtime error if we did that

        // move slow by 1 node
        slow = slow->next;
        // move fast by 2 nodes
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}
int main()
{

    return 0;
}