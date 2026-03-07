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

// IMP NOTE
/*THIS QUESTION IS ENTIRELY IDENTICAL TO "LEETCODE 88 MERGE TWO SORTED ARRAYS",
IF YOU ALREADY KNOW THAT QUESTION. THIS MIGHT FEEL TOO EASY
THE ONLY DIFF IS POINTER LOGIC"


// Problem Statement
/*You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list.
The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Example 1
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

// Two Pointers Approach
/*For Optimal Approach,
what we can do is start both linked lists at head and then compare their elements one by one
and ptrs only move for only one linked list at a time
Example:
if node 1 of linked list 1 < node 1 of linked list 2
only advanve node 1 of linked list 1 and so on for the the lists
at end also check if any one the list has not reached end, then that list has all greater numbers, directly append remaining part to it*/

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    // We create a dummy node which helps us build the final list easily
    // Dummy acts like a temporary head before the actual merged list
    ListNode *dummy = new ListNode(0);

    // current will always point to the last node of our merged list
    ListNode *current = dummy;

    // Two pointer idea
    // We start both pointers at head of both lists
    // and compare their values
    while (list1 != nullptr && list2 != nullptr)
    {

        // if list1 value is smaller or equal
        // attach that node to merged list
        if (list1->val <= list2->val)
        {

            // connect the existing node from list1
            current->next = list1;

            // move list1 forward
            list1 = list1->next;
        }
        else
        {

            // otherwise connect node from list2
            current->next = list2;

            // move list2 forward
            list2 = list2->next;
        }

        // move the stitching pointer forward
        // this always stays at last node of merged list
        current = current->next;
    }

    // At this point one of the lists is finished
    // the other list still has remaining nodes
    // since they are already sorted we can directly attach them

    if (list1 != nullptr)
        current->next = list1;
    else
        current->next = list2;

    // final merged list starts after dummy
    ListNode *result = dummy->next;

    // delete dummy as it was only temporary helper node
    delete dummy;

    return result;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    // Example sorted lists: 1->2->4 and 1->3->4
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode *merged = mergeTwoLists(list1, list2);

    cout << "Merged list: ";
    printList(merged);

    return 0;
}