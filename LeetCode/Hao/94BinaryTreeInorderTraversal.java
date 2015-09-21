
public class Solution {
    List<Integer> ans;
    
    private void inorder(TreeNode node) {
        if (node == null) {
            return;
        }
        
        inorder(node.left);
        ans.add(node.val);
        inorder(node.right);
    }
    
    public List<Integer> inorderTraversal(TreeNode root) {
        ans = new ArrayList<Integer>();
        inorder(root);
        return ans;
        
    }
}


public class Solution {
    public class StackNode {
        TreeNode node;
        int type; 
        public StackNode(TreeNode node, int type) {
            this.node = node;
            this.type = type;
        }
    }
    private final static int FIRST_IN_STACK = 0;
    private final static int SECOND_IN_STACK = 1;
    
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        if (root == null) {
            return result;
        }
        Stack<StackNode> stack = new Stack<StackNode>();
        stack.push(new StackNode(root, FIRST_IN_STACK));
        
        while (stack.empty() == false) {
            StackNode stackNode = stack.pop();
            
            if (stackNode.type == FIRST_IN_STACK) {
                if (stackNode.node.right != null) {
                    stack.push(new StackNode(stackNode.node.right, FIRST_IN_STACK));
                }
                stack.push(new StackNode(stackNode.node, SECOND_IN_STACK));
                if (stackNode.node.left != null) {
                    stack.push(new StackNode(stackNode.node.left, FIRST_IN_STACK));
                }
            } else if (stackNode.type == SECOND_IN_STACK) {
                result.add(stackNode.node.val);
            }
        }
        
        return result;
    }
}
