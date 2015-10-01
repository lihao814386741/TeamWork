class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int path = 0;
        _sumNumbersHelper(root, path);
        return _sum;
    };
private:
    int _sum = 0;
    void _sumNumbersHelper(TreeNode *root, int path) {
        if (!root->left && !root->right) {
            _sum += path * 10 + root->val;
        }
        
        if (root->left) _sumNumbersHelper(root->left, path * 10 + root->val);
        if (root->right) _sumNumbersHelper(root->right, path * 10 + root->val);
        
    }
};
