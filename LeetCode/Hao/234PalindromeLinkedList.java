/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode p;
    
    private boolean helper(ListNode node) {
        if (node == null) {
            return true;
        }
        
        
        boolean r = helper(node.next);
        
        if (r == false) {
            return false;
        }
        
        if (node.val != p.val) {
            return false;
        }
        p = p.next;
        
        return true;
    }
    
    public boolean isPalindrome(ListNode head) {
        p = head;
        
        return helper(head);
    }
}
