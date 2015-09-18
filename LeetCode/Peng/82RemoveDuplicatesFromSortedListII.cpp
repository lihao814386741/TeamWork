/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        while (head && head->next) {
            if (head->val == head->next->val) {
                int temp = head->val;
                while (head && head->val == temp) {
                    head = head->next;
                }
            } else { 
                current->next = head;
                current = current->next;
                head = head->next;
            }
        }
        current->next = head;
        return dummy->next;
    }
};