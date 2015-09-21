/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Do it recursively from the middle of the list
class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        
        ListNode* left = findMiddle(head);
        ListNode* middle = left->next;
        left->next = NULL;
        ListNode* right = middle->next;
        middle->next = NULL;
        
        TreeNode* root = new TreeNode(middle->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(right);
        return root;
    }
};