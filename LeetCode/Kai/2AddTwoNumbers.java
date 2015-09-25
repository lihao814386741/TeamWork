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
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        int carry = 0;
        
        while(l1!=null && l2!=null) {
            int digit1 = l1.val;
            int digit2 = l2.val;
            int sum = digit1 + digit2 + carry;
            ListNode node = new ListNode(sum%10);
            curr.next = node;
            curr = curr.next;
            carry = sum/10;
            l1 = l1.next;
            l2 = l2.next;
        }
        
        while(l1!=null) {
            int digit1 = l1.val;
            int sum = digit1 + carry;
            ListNode node = new ListNode(sum%10);
            curr.next = node;
            curr = curr.next;
            carry = sum/10;
            l1 = l1.next;
        }
        while(l2!=null) {
            int digit2 = l2.val;
            int sum = digit2 + carry;
            ListNode node = new ListNode(sum%10);
            curr.next = node;
            curr = curr.next;
            carry = sum/10;
            l2 = l2.next;
        }
        
        if(carry==1) curr.next = new ListNode(1);
        
        return dummy.next;
    }
    
}