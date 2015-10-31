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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
    
private:
    bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) {
            return true;
        }
        
        if (root->val > minVal && root->val < maxVal) {
            return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
        }
        
        return false;
    }
};
