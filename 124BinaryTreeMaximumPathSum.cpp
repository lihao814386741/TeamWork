/**
 * Definition for a binary tree node.
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/**
 * Corner case:
 * [-3]
 **/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return maxPath;
    }
private:
    int maxPathSumHelper(const TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int left = max(maxPathSumHelper(root->left), 0); // make sure left is positive here instead of lower level; 
        int right = max(maxPathSumHelper(root->right), 0);

        maxPath = max(maxPath, left + right + root->val);
        
        // Return the max local path.
        return max(left, right) + root->val;
    }
    
    int maxPath = INT_MIN;
};
