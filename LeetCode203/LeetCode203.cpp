// Remove all elements from a linked list of integers that have value val.
// Example:
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

#include <iostream>

//  Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {

        while (head != nullptr && head->val == val)
            head = head->next;
        if (head == nullptr)
            return head;

        ListNode *pointer = head;
        ListNode *freePointer = nullptr;

        while (pointer->next != nullptr)
        {
            std::cout << pointer->val << " ";

            if (pointer->next->val == val)
            {
                freePointer = pointer->next;
                pointer->next = freePointer->next;
                delete (freePointer);
            }
            else if (pointer->next != nullptr)
                pointer = pointer->next;
        }

        return head;
    }
};