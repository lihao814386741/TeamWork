/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

//solution 1:  Time Limit Exceeded
public class Solution {
    public void reorderList(ListNode head) {
        if(head==null || head.next==null || head.next.next==null) return;  //corner case
        
        ListNode node = head;
        while(node.next.next != null) node = node.next;
        node.next.next = head.next;
        head.next = node.next;
        node.next = null;
        reorderList(head.next.next);
    }
    
}


//solution 2
public class Solution {
    public void reorderList(ListNode head) {
        if(head==null) return;    //corner case
        
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null&& fast.next.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode first = head;
        ListNode second = slow.next;
        slow.next = null;
        
        second = reverseList(second);
        mergeLists(first, second);
    }
    
    public ListNode reverseList(ListNode head) {
        ListNode reversedPart = null;
        ListNode curr = head;
        while(curr != null) {
            ListNode next = curr.next;
            curr.next = reversedPart;
            reversedPart = curr;
            curr = next;
        }
        return reversedPart;
    }
    
    public void mergeLists(ListNode first, ListNode second) {
        while(second!=null) {
            ListNode temp = second.next;
            second.next = first.next;
            first.next = second;
            second = temp;
            first = first.next.next;
        }
    }
}
