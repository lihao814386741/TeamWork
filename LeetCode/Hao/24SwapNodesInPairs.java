/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private void helper(ListNode node) {
        if (node.next == null || node.next.next == null) {
            return;
        }
        
        ListNode tmp = node.next;
        node.next = node.next.next;
        tmp.next = node.next.next;
        node.next.next = tmp;
        helper(tmp);
    }
    
    
    public ListNode swapPairs(ListNode head) {
        ListNode p = new ListNode(0);
        p.next = head;
        
        helper(p);
    
        return p.next;    
    }
}
