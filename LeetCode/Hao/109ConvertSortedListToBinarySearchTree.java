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
public class Solution {
    ListNode node;
    private TreeNode inorder(int size) {
        if (size == 0) {
            return null;
        }
        
        int leftSize = size / 2;
        int rightSize = size - leftSize - 1;
        
        TreeNode leftTree = inorder(leftSize);
        TreeNode root = new TreeNode(node.val);
        node = node.next;
        TreeNode rightTree = inorder(rightSize);
        
        root.left = leftTree;
        root.right = rightTree;
        
        return root;
    }
    public TreeNode sortedListToBST(ListNode head) {
        int count = 0;
        for (ListNode p = head; p != null ; p = p.next) {
            count ++;
        }
        this.node = head;
        
        return inorder(count);
    }
}
