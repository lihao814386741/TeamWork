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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode *preHead = new ListNode(INT_MIN);
        preHead->next = head;
        ListNode *pre = preHead;
        ListNode *second = pre->next->next;
        while (second) {
            //swap
            pre->next->next = second->next;
            second->next = pre->next;
            pre->next = second;
            
            //update
            pre = pre->next->next;
            second = pre->next;
            if (!second) {
                // The last pair only have one
                break;
            }
            second = second->next;
        }
        
        head = preHead->next;
        delete preHead;
        return head;
    }
};
