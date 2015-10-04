//recursive pre-order
public class Solution {
    public TreeNode invertTree(TreeNode root) {
        invert(root);
        return root;
    }
    
    public void invert(TreeNode node) {
        if(node==null) return;
        
        TreeNode tempNode = node.left;
        node.left = node.right;
        node.right = tempNode;
        
        invert(node.left);
        invert(node.right);
    }
    
}