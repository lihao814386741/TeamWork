/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Use dummy head will be easy to handle boundries.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* last = dummy;
        ListNode* current, * next, * left, * right;
        for (int i = m - 1; i > 0 ; i--) {
            last = last->next;
        }
        left = last;
        right = last->next;
        current = last->next;
        next = current->next;
        
        for (int i = n - m; i > 0; i--) {
            last = current;
            current = next;
            next = next->next;
            current->next = last;
        }
        right->next = next;
        left->next = current;
        return dummy->next;
    }
};