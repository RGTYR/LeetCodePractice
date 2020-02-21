/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* currentPointer1 = l1;
    struct ListNode* currentPointer2 = l2;
    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 0; head->next = NULL;
    struct ListNode* listNode = head;
    int sum = 0;
    int carry = 0;

    while (currentPointer1 || currentPointer2 || carry > 0)
    {
        int val1 = currentPointer1 ? currentPointer1->val : 0;
        int val2 = currentPointer2 ? currentPointer2->val : 0;

        sum = val1 + val2 + carry;
        carry = 0;

        if (sum >= 10)
        {
            sum = sum % 10;
            carry = 1;
        }

        listNode->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        listNode->next->val = sum;
        listNode->next->next = NULL;
        listNode = listNode->next;

        if (currentPointer1)
            currentPointer1 = currentPointer1->next;
        if (currentPointer2)
            currentPointer2 = currentPointer2->next;
    }

    listNode = head->next;
    free(head);
    return listNode;
}
