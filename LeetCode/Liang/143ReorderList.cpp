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
    void reorderList(ListNode* head) {
        // Special case.
        if (!head) {
            return;
        }
        
        // Split.
        ListNode *fast = head, *slow = head;
        while (fast) {
            fast = fast->next;
            if (!fast || !fast->next) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *first = head;
        ListNode *second = slow->next;
        slow->next = nullptr;
        // Revert the second half.
        second = revertList(second);
        
        // Merge and generate reorder list.
        head = mergeList(first, second);
    }
private:
    ListNode *revertList(ListNode *head) {
        ListNode *preHead = new ListNode(INT_MIN);
        while (head) {
            ListNode *tmp = head->next;
            head->next = preHead->next;
            preHead->next = head;
            head = tmp;
        }
        head = preHead->next;
        delete preHead;
        return head;
    }
    
    ListNode *mergeList(ListNode *first, ListNode *second) {
        ListNode *itrFirst = first, *itrSecond = second;
        while (itrFirst && itrSecond) {
            ListNode *tmp = itrSecond->next;
            itrSecond->next = itrFirst->next;
            itrFirst->next = itrSecond;
            itrFirst = itrSecond->next;
            itrSecond = tmp;
        }
        return first;
    }
};
