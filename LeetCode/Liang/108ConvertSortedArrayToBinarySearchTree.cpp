class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBSTHelper(num, 0, num.size() - 1);
	}
private:
	TreeNode *sortedArrayToBSTHelper(vector<int> &num, int begin, int end) {
		if (begin > end) {
			return nullptr;
		}
		
		if (begin == end) {
			return new TreeNode(nums.at(begin));
		}
		
		int mid = begin + (end - begin) / 2;
		TreeNode *root = new TreeNode(num.at(mid));
		root->left = sortedArrayToBSTHelper(num, begin, mid - 1);
		root->right = sortedArrayToBSTHelper(num, mid + 1, end);
		return root;
	} 
};
