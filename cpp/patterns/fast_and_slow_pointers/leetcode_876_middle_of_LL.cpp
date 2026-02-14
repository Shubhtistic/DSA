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

// Problem Statement
/*Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

// Easy Approach
/*Unline a array its not that easy to find middle of list
So what we can do is simply run a loop first and then find the total nodes(length of LL)
and then we run 2nd loop until middle element*/
// Imp Note: This is a easy Approach, if asked in interview the interviewer may ask you to do it in single pass
// We will do Optimal version after this

// T.C -> O(n)
// S.C -> O(1)

ListNode *middleNode_easy(ListNode *head)
{

    ListNode *temp = head;
    int len = 0;
    int mid = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    mid = len / 2;
    temp = head;
    for (int i = 1; i <= mid; i++)
    {
        temp = temp->next;
    }

    return temp;
    ;
}

// Optimal Approach
/*We can now use the fast-slow ptr approach for optimal approach
if you think for a moment what does fast do -> its run twice faster than slow
So by that logic when fast reaches end , slow will be at middle.
Real Life Example:
Two friends start running from the same starting point on a straight road.
Friend A runs at normal speed (slow pointer).
Friend B runs at double speed (fast pointer).
They start together.
What happens?
When the faster friend reaches the end of the road:
He has covered the full distance.
The slower friend, running at half the speed, has covered exactly half the distance.
Half of the road = middle of the road.
That’s it
*/

// T.C -> O(n) ... SINGLE PASS
// S.C -> O(1)

ListNode *middleNode_optimal(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{

    return 0;
}