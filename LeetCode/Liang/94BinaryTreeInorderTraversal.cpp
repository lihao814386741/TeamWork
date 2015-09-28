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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStk;
        vector<int> result;
        while (root || !nodeStk.empty()) {
            // Put the left most branch into stack
            while (root) {
                nodeStk.push(root);
                root = root->left;
            }
            // Traverse the left tree;
            TreeNode *top = nodeStk.top();
            nodeStk.pop();
            result.push_back(top->val);
            root = top->right;
        }
        return result;
    }
};
