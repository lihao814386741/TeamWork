/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head; //corner case
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode curr = dummy;
        while(curr.next!=null && curr.next.next!=null) {
            ListNode p1 = curr.next;
            ListNode p2 = curr.next.next;
            p1.next = p2.next;
            p2.next = p1;
            curr.next = p2;
            curr = curr.next.next;
        }
        return dummy.next;
    }
    
}