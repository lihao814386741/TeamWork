/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/**
 * My time complexity is o(n), where n is the total number of the node.
 **/
 
// static int countNum = 0; This will definitely have problem when the class is used in multipal test.
// static int ans = 0;
// int countNum = 0;
// int ans = 0;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestHelper(root, k);
        return ans;
    }
private:
    int ans;
    int countNum = 0;
    void kthSmallestHelper(TreeNode *root, int k) {
        if (root->left) {
            kthSmallestHelper(root->left, k);
        }
        ++countNum;
        if (countNum == k) {
            ans = root->val;
            return; // Here is good.
        }
        if (root->right) {
            kthSmallestHelper(root->right, k);
        }
    }
};
