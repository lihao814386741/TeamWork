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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        assert(m >= 1 && m <= n);
        
        // Special case.
        if (m == n) {
            return head;
        }
        
        int step = n - m;
        
        // Traverse to position m
        ListNode *preHead = new ListNode(INT_MIN);
        preHead->next = head;
        ListNode *preFirst = preHead;
        while (m > 1) {
            --m;
            preFirst = preFirst->next;
        }
        
        // Reverse node from [m...n]
        ListNode *last = preFirst->next, *itr = preFirst->next->next;
        while (step > 0 && itr) {
            --step;
            ListNode *tmp = itr->next;
            itr->next = preFirst->next;
            preFirst->next = itr;
            itr = tmp;
        }
        last->next = itr;
        
        // Return
        head = preHead->next;
        delete preHead;
        return head;
    }
};
