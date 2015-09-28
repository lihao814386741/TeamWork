/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStk;
        if (root) {
            nodeStk.push(root);
        }
        
        while (!nodeStk.empty()) {
            TreeNode *top = nodeStk.top();
            nodeStk.pop();
            result.push_back(top->val);
            if (top->left) {
                nodeStk.push(top->left);
            }
            
            if (top->right) {
                nodeStk.push(top->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
