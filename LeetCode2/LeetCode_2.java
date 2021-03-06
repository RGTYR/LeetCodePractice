/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode currentPointer1 = l1;
        ListNode currentPointer2 = l2;
        ListNode head = new ListNode(0);
        ListNode listNode = head;
        int sum = 0;
        int carry = 0;

        while (currentPointer1 != null || currentPointer2 != null || carry > 0)
        {
            int val1 = currentPointer1 != null ? currentPointer1.val : 0;
            int val2 = currentPointer2 != null ? currentPointer2.val : 0;
            sum = val1 + val2 + carry;
            carry = 0;
            
            if (sum >= 10)
            {
                sum = sum % 10;
                carry = 1;
            }
            
            listNode.next = new ListNode(sum);
            listNode = listNode.next;

            if (currentPointer1 != null)
                currentPointer1 = currentPointer1.next;
            if (currentPointer2 != null)
                currentPointer2 = currentPointer2.next;
        }
        
        return head.next;
    }
}