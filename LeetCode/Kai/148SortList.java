/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if(head==null || head.next == null) return head;
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null && fast.next.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode mid = slow.next;
        slow.next = null;
        ListNode p1 = sortList(head);
        ListNode p2 = sortList(mid);
        return merge(p1, p2);   //divide and conquer, merge sort
    }
    
    public ListNode merge(ListNode p1, ListNode p2) {
        if(p1.val>p2.val) {
            ListNode temp = p2;
            p2 = p1;
            p1 = temp;
        }
        ListNode head = p1;
        while(p1!=null && p2!=null) {
            if(p1.next == null) {
                p1.next = p2;
                break;
            }
            if(p1.val<=p2.val && p1.next.val>=p2.val) {
                ListNode tmp = p2.next;
                p2.next = p1.next;
                p1.next = p2;
                p2 = tmp;
                p1 = p1.next;
            } else {
                p1 = p1.next;
            }
        }
        return head;
        
    }
    
}