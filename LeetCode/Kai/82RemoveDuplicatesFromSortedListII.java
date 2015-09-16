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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode p = dummy;
        while(p.next!=null && p.next.next!=null) {
            if(p.next.val==p.next.next.val) {
                int duplicate = p.next.val;
                while(p.next!=null && p.next.val==duplicate) p.next = p.next.next;
            } else {
                p = p.next;
            }
        }
        return dummy.next;
    }
    
}