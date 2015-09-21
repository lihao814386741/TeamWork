/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode small = new ListNode(0);
        ListNode big = new ListNode(0);
        small.next = head;
        big.next = head;
        ListNode c = big;
        ListNode start = small;

        
        for (ListNode p = head; p != null; p = p.next) {
            if (p.val < x) {
                small.next = p;
                small = small.next;
            } else {
                big.next = p;
                big = big.next;
            }
        }
        big.next = null;
        small.next = c.next;
        
        return start.next;
    }
}
