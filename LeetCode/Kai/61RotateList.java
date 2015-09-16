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
        if(head == null) return head;  //corner case
        
        //create a cycle
        int count = 0;
        ListNode node = head;
        while(node.next != null) {
            node = node.next;
            count++;
        }
        node.next = head;
        
        //break cycle from new head
        for(int i=0; i<count-k%(count+1); i++) {
            head = head.next;
        }
        ListNode newHead= head.next;
        head.next = null;
        
        return newHead;
    }
    
}