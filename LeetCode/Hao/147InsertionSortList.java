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
        ListNode preNode = new ListNode(0);
        ListNode p = head;
        ListNode tmp = null;
        boolean isChange;
        while (p != null) {
            isChange = false;
            for (ListNode q = preNode; q  != null; q = q.next) {
                if (q.next == null || q.next.val > p.val) {
                    tmp = p.next;
                    p.next = q.next;
                    q.next = p;
                    p = tmp;
                    isChange = true;
                    break;
                } 
            }
        }
        
        return preNode.next;
    }
}
