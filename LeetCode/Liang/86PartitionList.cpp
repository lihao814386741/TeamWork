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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller = new ListNode(INT_MIN);
        ListNode *bigger = new ListNode(INT_MIN);
        ListNode *sTail = smaller, *bTail = bigger;
        while (head) {
            ListNode *tmp = head->next;
            if (head->val < x) {
                sTail->next = head;
                sTail = sTail->next;
            } else {
                bTail->next = head;
                bTail = bTail->next;
            }
            head = tmp;
        }
        sTail->next = bigger->next;
        head = smaller->next;
        bTail->next = nullptr;//Don't forget this.
        delete bigger;
        delete smaller;
        return head;
    }
};
