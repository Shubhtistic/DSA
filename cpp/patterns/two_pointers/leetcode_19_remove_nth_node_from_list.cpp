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
/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]*/

// Easy approach
/*In this we can use Two pass (2 loops seperately), the first loops finds the total size of list
and in 2nd loop we traverse to the element to be deleted and delete it*/

// T.C -> O(n)
// S.C -> O(1)

ListNode *simple_removeNthFromEnd(ListNode *head, int n)
{
    int size = 0;
    ListNode *s = head;
    while (s != nullptr)
    {
        size++;
        s = s->next;
    }

    if (n == size)
    {
        ListNode *newHead = head->next;
        delete head;
        return newHead;
    }

    int target = size - n;
    ListNode *temp = head;
    // Node Just before The target Node
    for (int i = 1; i < target; i++)
    {
        temp = temp->next;
    }

    ListNode *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;

    return head;
}

// Two Pointer -> Optimal Approach
/* In this we use an dummy variable which always points to the head,
so even we have to remove head we ca easily without messy if-else conditions.
We start use the fast and slow pointer technique in this, where one pointer moves multiple steps at once and one moves normally
We start moving the slow pointer only when fast reaches n+1 steps, by this we keep the distance b/w them as n+1 so slow land at the node just behind the node to delete.
Real World Example:-
Imagine walking on a road.
Person A starts walkin
Person B starts after A has already walked n steps

Now:
The distance between them is always n
When A reaches the end of the road,
B is exactly n steps behind the end
 */

// T.C -> O(n)
// S.C -> O(1)

ListNode *optimal(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    /* We assume this as start
    so now every node of original list has an previous link*/

    ListNode *fast = dummy;
    ListNode *slow = dummy;
    // Both start at dummy

    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }
    /* n+1 is crucial as it wil avoid
    slow pointer exactly reaching the node to be deleted,
    it will land just before it; */

    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *to_delete = slow->next;
    // can be any node, even the head
    // using dummy we handled that edge case
    slow->next = to_delete->next;
    delete to_delete;

    return dummy->next;
    // correctly returns new head if head was removed
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List1\n";
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << " \nUsing Simple Approach\n";
    ListNode *t = simple_removeNthFromEnd(head, 2);
    while (t != nullptr)
    {
        cout << t->val << " ";
        t = t->next;
    }

    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "\n\nOriginal List2\n";
    ListNode *temp1 = head1;
    while (temp1 != nullptr)
    {
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }

    cout << "\n Using Optimal Approach\n";
    ListNode *t1 = optimal(head1, 2);
    while (t1 != nullptr)
    {
        cout << t1->val << " ";
        t1 = t1->next;
    }

    return 0;
}
