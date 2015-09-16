/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode curr = dummy;
        for(int i=0; i<m-1; i++) curr = curr.next;  // curr position: m-1
        for(int i=0; i<n-m; i++) {
            ListNode p = curr;
            for(int j=0; j<n-m-i; j++) p = p.next;   //p position: n-1
            ListNode tmp = p.next.next;
            p.next.next = curr.next;
            curr.next = p.next;
            p.next = tmp;
            
            curr = curr.next;
        }
        return dummy.next;
    }
    
}