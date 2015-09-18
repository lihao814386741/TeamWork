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
class Solution {
public:
    TreeNode* sortedListToBST_Liang(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        
        if (!head->next) {
            return new TreeNode(head->val);
        }
        
        // Find mid point
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *preMid = dummy, *end = dummy;
        while (end && end->next) {
            end = end->next->next;
            if (!end) {
                break;
            }
            preMid = preMid->next;
        }
        
        TreeNode *root = new TreeNode(preMid->next->val);
        ListNode *secondHalf = preMid->next->next;
        preMid->next = nullptr;
        ListNode *firstHalf = dummy->next;
        root->left = sortedListToBST(firstHalf);
        root->right = sortedListToBST(secondHalf);
        delete dummy;
        return root;
    }
};
