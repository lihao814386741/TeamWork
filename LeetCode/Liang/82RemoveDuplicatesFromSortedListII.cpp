/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Assume no circle.
 **/
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;    
        }
        
        ListNode *preHead = new ListNode(INT_MIN);
        ListNode *tail = preHead;
        ListNode *first = head, *second = head;
        bool isDup = false;
        while (second->next) {
            second = second->next;
            if (first->val != second->val) {
                if (!isDup) {
                    tail->next = first;
                    tail = tail->next;
                }
                isDup = false;
                first = second;
            } else {
                isDup = true;
            }
        }
        
        if (!isDup) {
            tail->next = first;
            tail = tail->next;
        }
        tail->next = nullptr;
        head = preHead->next;
        delete preHead;
        return head;
    }
};
