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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        
        vector<int> result;
        stack<TreeNode*> nodeStk;
        nodeStk.push(root);
        while (!nodeStk.empty()) {
            TreeNode *tmp = nodeStk.top();
            nodeStk.pop(); // Thought this like a Queue and put it to __
            result.push_back(tmp->val);
            if (tmp->right) nodeStk.push(tmp->right);
            if (tmp->left) nodeStk.push(tmp->left);
            // nodeStk.pop();
        }
        return result;
    }
};
