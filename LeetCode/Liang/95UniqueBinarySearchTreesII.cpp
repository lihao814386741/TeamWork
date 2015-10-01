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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result = generateHelper(1, n);
        return result;
    }
    
private:
    vector<TreeNode*> combineHelper(vector<TreeNode*> &first, vector<TreeNode*> &second, int rootVal) { // Why I cannot use TreeNode *root here as the API?
        vector<TreeNode*> result;
        for (int i = 0; i < first.size(); ++i) {
            for (int j = 0; j < second.size(); ++j) {
                TreeNode *root = new TreeNode(rootVal);
                root->left = first.at(i);
                root->right = second.at(j);
                result.push_back(root);
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateHelper(int begin, int end) {
        if (begin > end) {
            return vector<TreeNode*>(1, nullptr);
        }
        
        if (begin == end) {
            return vector<TreeNode*>(1, new TreeNode(begin));
        }
        
        vector<TreeNode*> result;
        for (int i = begin; i <= end; ++i) {
            vector<TreeNode*> left = generateHelper(begin, i - 1);
            vector<TreeNode*> right = generateHelper(i + 1, end);
            vector<TreeNode*> tmpRes = combineHelper(left, right, i);
            result.insert(result.end(), tmpRes.begin(), tmpRes.end()); // Not result.back();
        }
        return result;
    }
};
