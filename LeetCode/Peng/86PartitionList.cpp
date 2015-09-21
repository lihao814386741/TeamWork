/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Use two head, one collect small number, one collect big number, then link them together
//Notice: the rightmost should be NULL!!!
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* dummyLeft = new ListNode(-1);
        ListNode* dummyRight = new ListNode(-1);
        ListNode* left = dummyLeft, * right = dummyRight;
        while (head) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        left->next = dummyRight->next;
        right->next = NULL;
        left = dummyLeft->next;
        delete dummyLeft;
        delete dummyRight;
        return left;
    }
};