/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    
    public class PriorityComparator implements Comparator<ListNode>
    {
        public int compare(ListNode e1, ListNode e2)
        {
            return e1.val - e2.val;
        }
    }
    public ListNode mergeKLists(List<ListNode> lists) {
       
        if (lists == null)
        {
            return null;     
        }
        if (lists.size() == 0)
        {
            return null;
        }
        
        ListNode head = new ListNode(0);
        
        ListNode p = head;
        
        PriorityQueue<ListNode> q = new PriorityQueue<ListNode>(lists.size(), new PriorityComparator());
        
        
        for (ListNode list : lists)
        {
            if (list != null)
            {
                q.add(list);   
            }
        }
        
        
        while (q.size() > 0)
        {
            ListNode tmp = q.poll();
            p.next = tmp;
            
            if (tmp.next != null)
            {
                q.add(tmp.next);
            }
            
            
            p = p.next;
            
        }
        
        
        return head.next;
    }
}
