//Recursive
public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<Integer>();
        inOrder(root, result);
        return result;
    }
    
    public void inOrder(TreeNode root, List<Integer> result) {
        if(root!=null && root.left!=null) inOrder(root.left, result);
        if(root!=null) result.add(root.val);
        if(root!=null && root.right!=null) inOrder(root.right, result);
    }
}



//Iterative
public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode node = root;
        
        while(node!=null || !stack.isEmpty()) {
            while(node!=null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            result.add(node.val);
            node = node.right;
        }
        return result;
    }
}