/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


//O(n*logn)
//Build from root
//pre-order
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if(head==null) return null;
        if(head.next==null) return new TreeNode(head.val);   //corner case
        
        ListNode fast = head.next;      //use head.next here, in order to let slow be mid-1 after while loop
        ListNode slow = head;
        while(fast.next!=null && fast.next.next!=null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        
        TreeNode root = new TreeNode(slow.next.val);
        ListNode second = slow.next.next;
        slow.next = null;
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(second);
        return root;
    }
    
}


//O(n)
//build from botton left
//in-order
public class Solution {
    ListNode h;
    
    public TreeNode sortedListToBST(ListNode head) {
        h= head;
        ListNode node = head;
        int size = 0;
        while(node!=null) {
            node = node.next;
            size++;
        }
        
        TreeNode root = createBST(0, size-1);
        return root;
    }
    
    public TreeNode createBST(int left, int right) {
        if(left>right) return null;
        
        int mid = (left+right)/2;
        TreeNode leftChild = createBST(left, mid-1);
        TreeNode root = new TreeNode(h.val);
        h = h.next;
        TreeNode rightChild = createBST(mid+1, right);
        
        root.left = leftChild;
        root.right = rightChild;
        
        return root;
    }
}

