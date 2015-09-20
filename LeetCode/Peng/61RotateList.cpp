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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        
        ListNode* current = head;
        int length = 0;
        while (current) {
            length++;
            current = current->next;
        }
        
        int tempK = k % length;
        current = head;
        ListNode* end = head;
        while (tempK) {
            end = end->next;
            tempK--;
        }
        while (end->next) {
            current = current->next;
            end = end->next;
        }
        end->next = head;
        head = current->next;
        current->next = NULL;
        return head;
    }
};