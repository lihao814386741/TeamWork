/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
   private ListNode mergeSort(ListNode node, int size) {
        if (size <= 1) {
            return node;
        }
        int midSize = (size + 1)/ 2;
        ListNode p = node; 
        ListNode midNode; 
        for (int i = 0; i < midSize - 1; i ++) {
            p = p.next;
        }
        midNode = p.next;
        
        node = mergeSort(node, midSize);
        midNode = mergeSort(midNode, size - midSize);
        
        p = new ListNode(0);
        ListNode head = p; 
        int countFirst = 0;
        int countSecond = 0; 
        int count = 0;
        
        
        while (count < size) {
        	if (countFirst >= midSize) {
        		p.next = midNode;
        		p = p.next;
        		midNode = midNode.next;
        	} else if (countSecond >= size - midSize) {
        		p.next = node;
        		p = p.next;
        		node = node.next;
        	}else if (node.val < midNode.val) {
                p.next = node;
                p = p.next;
                node = node.next;
                countFirst ++;
            } else {
                p.next = midNode;
                p = p.next;
                midNode = midNode.next;
                countSecond ++;
            }
            count ++;
        }
        p.next = midNode;
        
        return head.next;
    }
    
    public ListNode sortList(ListNode head) {
        int size = 0;
        
        for (ListNode p = head; p != null; p = p.next) {
            size ++;
        }
        
        return mergeSort(head, size);
    }
}
