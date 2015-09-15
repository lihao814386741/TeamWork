/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode reverse(ListNode node) {
        if (node.next == null){
            return node;
        }
        
        ListNode n = reverse(node.next);
        n.next = node;
        return node;
    }
    
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return head;
        }
        
        ListNode p = head;
        
        while (p.next != null) {
            p = p.next;
        }
        
        reverse(head);
        head.next = null;
        
        return p;
        
    }
}
