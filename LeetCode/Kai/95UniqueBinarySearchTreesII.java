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
    public List<TreeNode> generateTrees(int n) {
        return dfs(1, n);
    }
    //This structure is similar to LeetCode 241: Different Ways to Add Parentheses
    public List<TreeNode> dfs(int left, int right) {
        List<TreeNode> result = new LinkedList<TreeNode>();
        
        // if(left==right) {         //redundant code. This condition has been taken care of in the for loop below
        //     TreeNode node = new TreeNode(left);
        //     result.add(node);
        //     return result;
        // }
        
        if(left>right) {
            TreeNode node = null;
            result.add(node);
            return result;
        }
        
        for(int i=left; i<=right; i++) {
            List<TreeNode> leftTrees = dfs(left, i-1);
            List<TreeNode> rightTrees = dfs(i+1, right);
            for(TreeNode leftTree : leftTrees) {
                for(TreeNode rightTree : rightTrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = leftTree;
                    root.right = rightTree;
                    result.add(root);
                }
            }
        }
        
        return result;
    }
    
}