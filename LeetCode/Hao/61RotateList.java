/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        
        ListNode p = head;
        int size = 0;
        
        while (p != null) {
            p = p.next;
            size ++;
        }
        
        k %= size;
        
        ListNode fast = head;
        ListNode slow = head;

        for (int i = 0; i < k; i ++) {
            fast = fast.next;
        }        
        
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        
        fast.next = head;
        head = slow.next;
        slow.next = null;
        
        return head;
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {

    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode p = head;
        ListNode n = head.next;
        
        while ( n != null) {
            ListNode tmp = n.next;
            n.next = p;
            p = n;
            n = tmp;
        }
        
        head.next = null;
        
        return p;
    }
}
