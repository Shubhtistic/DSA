#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// problem statement
/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 */

// Easy / Brute Appraoch
/*This is very straightforward Approach
1st step -> find total length of list.
total step -n = the node to delete
2nd step -> use a loop to reach the node just before the node to delete
then remove the node to be deleted and set the node before that to next of node to be deleted node

Imp Case,
if total length-n == 0, remove the first node i.e head
1) check is linked list only has 1 element i.e only head then set head also to be a Null
2) if head has some next value then move head to next node and delete old head*/

// T.C -> O(n + m)
// S.c -> O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *removeNthFromEnd_brute(ListNode *head, int n)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }

    int target = len - n;
    // delete
    if (target == 0)
    {
        if (head->next != nullptr)
        {
            ListNode *to_del = head;
            head = head->next;
            delete to_del;
            return head;
        }
        else if (head->next == nullptr)
        {
            ListNode *to_del = head;
            head = nullptr;
            delete to_del;
            return head;
        }
    }
    ListNode *t = head;
    for (int i = 1; i < target; i++)
    {
        t = t->next;
    }
    // t exactly before the node or one node behind the node to delete
    ListNode *to_del = t->next;
    t->next = to_del->next;
    delete to_del;
    return head;
}

// Optimal Approach
/*This question uses fast and slow ptrs not like we use normally, its a bit different than usual.
Instead of moving Fast 2x and slow 1x what we do is me first only move fast ptr n steps and then start moving slow
what this does beautifully is one we are n steps ahead of slow ptr and when fast reaches the end slow is exactly n steps behind end

Real Life Analogy,
You and your friend start a toy car race, but your start 5 meters or steps ahead of you,
both toy car have the same maximum speed, so both will run at same speed throughout the race,
and when your friend reaches the finish line, you will be exactly 5 meters or steps behind him.
This question also follows same logic*/

// T.C -> O(n+m) m -> to reach n steps ahead of slow
// S.C -> O(1)

ListNode *removeNthFromEnd_optimal(ListNode *head, int n)
{ // start a dummmyy node to properly move both at correct position
    // this also makes deletion easy as we dont ahve to worry about edge cases like linked list having only 1 node
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // slow exactly before node to be deleted
    ListNode *to_del = slow->next;
    slow->next = slow->next->next;
    delete to_del;

    return dummy->next;
}

int main()
{

    return 0;
}