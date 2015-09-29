/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (!root) {
        	return;
   		}
    
    	TreeLinkNode *dummy = new TreeLinkNode(0);
    	TreeLinkNode *tail = dummy;
    	while (root) {
        	if (root->left){
            	tail->next = root->left;
            	tail = tail->next;
        	}
        
        	if (root->right) {
            	tail->next = root->right;
            	tail = tail->next;
        	}
        	root = root->right; // Always forget this.
    	}
    
    	root = dummy->next;
    	delete dummy;
    	connect(root);     
    }
};
