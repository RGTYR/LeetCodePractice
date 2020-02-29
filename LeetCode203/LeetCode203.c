// Remove all elements from a linked list of integers that have value val.
// Example:
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

#include <stdlib.h>

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode * prehead = malloc(sizeof(struct ListNode));
    prehead->next = head;
    struct ListNode * pointer = prehead;
    struct ListNode * freePointer = NULL;

    while (pointer != NULL && pointer->next != NULL)
    {
        if (pointer->next->val == val)
        {
            freePointer = pointer->next;
            pointer->next = pointer->next->next;
            free(freePointer);
        }
        else
        {
            pointer = pointer->next;
        }
    }
    
    head = prehead->next;
    free(prehead);

    return head;

}
