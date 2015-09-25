/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode p = result;
        int carry = 0;
        
        while (l1 != null || l2 != null) {
            int number = 0;
            if (l1 == null) {
                number = l2.val + carry;
                l2 = l2.next;
            } else if (l2 == null) {
                number = l1.val + carry;
                l1 = l1.next;
            } else {
                number = l1.val + l2.val + carry;
                l1 = l1.next;
                l2 = l2.next;
            }
            
            carry = number >= 10 ? 1 : 0;
            number %= 10;
            
            result.next = new ListNode(number);
            result = result.next;
        }
        
        if(carry != 0) {
            result.next = new ListNode(1);
        }
        
        
        return p.next;
        
    }
}
