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
        ListNode dummy = new ListNode(0);
        ListNode newListDummy = new ListNode(0);
        dummy.next = head;
        ListNode curr = dummy;
        ListNode newCurr = newListDummy;
        while(curr.next!=null) {
            if(curr.next.val<x) curr = curr.next;
            else {
                newCurr.next = curr.next;
                curr.next = curr.next.next;
                newCurr.next.next = null;
                
                newCurr = newCurr.next;
            }
        }
        curr.next = newListDummy.next;
        return dummy.next;
        
    }
    
}