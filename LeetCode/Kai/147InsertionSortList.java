/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = null;          //create a new list for insertion
        ListNode pre = dummy;
        ListNode curr = head;
        while(curr!=null) {
            while(pre.next!=null && pre.next.val<=curr.val) pre = pre.next;
            
            ListNode tmp = curr.next;
            curr.next = pre.next;
            pre.next = curr;
            curr = tmp;
            pre = dummy;
        }
        return dummy.next;
    }
    
}