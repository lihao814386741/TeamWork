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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftDeepth = leftMostDeepth(root);
        int rightDeepth = rightMostDeepth(root);
        
        if (leftDeepth == rightDeepth) {
            return (1 << leftDeepth) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
private:
    int leftMostDeepth(TreeNode *root) {
        int result = 0;
        while (root) {
            ++result;
            root = root->left;
        }
        return result;
    }
    
    int rightMostDeepth(TreeNode *root) {
        int result = 0;
        while (root) {
            ++result;
            root = root->right;
        }
        return result;
    }
};
