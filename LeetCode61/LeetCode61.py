"""
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1.2.3.4.5.None, k = 2
Output: 4.5.1.2.3.None
Explanation:
rotate 1 steps to the right: 5.1.2.3.4.None
rotate 2 steps to the right: 4.5.1.2.3.None
Example 2:

Input: 0.1.2.None, k = 4
Output: 2.0.1.None
Explanation:
rotate 1 steps to the right: 2.0.1.None
rotate 2 steps to the right: 1.2.0.None
rotate 3 steps to the right: 0.1.2.None
rotate 4 steps to the right: 2.0.1.None 
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head == None or head.next == None:
            return head

        pointer = head
        size = 1

        while pointer.next != None:
            pointer = pointer.next
            size += 1

        pointer.next = head
        order = size - k % size
        pointer = head

        while order > 1:
            pointer = pointer.next
            order -= 1

        head = pointer.next
        pointer.next = None

        return head
