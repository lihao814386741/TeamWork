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
        if (head == null || head.next == null) {
            return head;
        }
        if (n == m) {
            return head;
        }
        
        ListNode p = new ListNode(1);
        p.next = head;
        ListNode ans = p;
        
        for (int i = 1; i < m; i ++) {
            p = p.next;
        }
        
        ListNode pre = p.next;
        ListNode cur = p.next.next;
        
        for (int i = 0; i < n - m; i ++) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        
        ListNode tmp = p.next;
        p.next = pre;
        tmp.next = cur;
        
        return ans.next;
    }
}
