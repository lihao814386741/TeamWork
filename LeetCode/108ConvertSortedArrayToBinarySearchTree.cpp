class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBSTHelper(num, 0, nums.size() - 1);
	}
private:
	TreeNode *sortedArrayToBSTHelper(vector<int> &num, int begin, int end) {
		if (begin > end) {
			return;
		}
		
		if (begin == end) {
			return new TreeNode(nums.at(begin));
		}
		
		int mid = begin + (end - begin) / 2;
		TreeNode *root = new TreeNode(nums.at(mid));
		root->left = sortedArrayToBSTHelper(num, begin, mid - 1);
		root->right = sortedArrayToBSTHelper(num, mid + 1, end);
		return root;
	} 
};
