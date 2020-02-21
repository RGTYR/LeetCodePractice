# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        currentPointer1 = l1
        currentPointer2 = l2
        head = ListNode(0)
        listNode = head
        sum = 0
        carry = 0

        while (currentPointer1 != None or currentPointer2 != None or carry > 0):
            val1 = currentPointer1.val if currentPointer1 != None else 0
            val2 = currentPointer2.val if currentPointer2 != None else 0
            sum = val1 + val2 + carry
            carry = 0
            
            if (sum >= 10):
                sum = sum % 10
                carry = 1
            
            listNode.next = ListNode(sum)
            listNode = listNode.next

            if (currentPointer1 != None):
                currentPointer1 = currentPointer1.next
            if (currentPointer2 != None):
                currentPointer2 = currentPointer2.next
        
        return head.next