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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* current = dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) {
            current->next = l1;
        } else if (l2) {
            current->next = l2;
        }
        return dummyHead->next;
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode* middle = findMiddle(head);
        if (!middle || !middle->next) {
            return head;
        }
        ListNode* next = middle->next;
        middle->next = NULL;
        return mergeTwoLists(sortList(head), sortList(next));
    }
};