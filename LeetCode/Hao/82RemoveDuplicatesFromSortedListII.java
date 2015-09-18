/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        int last = 0; 
        ListNode t = new ListNode(0);
        t.next = head;
        ListNode result = t;
        
        for (ListNode p = head; p != null; p = p.next) {
            if (p == head) {
                last = p.val;
                if (last != p.next.val) {
                    t.next = p;
                    t = t.next;
                }
            } else if (p.val != last && (p.next == null || p.next.val != p.val)) {
                t.next = p;
                t = t.next;
                last = p.val;
            } else if (p.val != last) {
                last = p.val;
            }
        }
        t.next = null;
        
        return result.next;
        
    }
}
