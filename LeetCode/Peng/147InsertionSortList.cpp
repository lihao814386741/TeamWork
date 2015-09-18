/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//1. Only when the right number is larger than the left number, we need //to do insert
//2. Try do less operation to save time
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = head;
        dummy->next = head;
        head = head->next;
        
        while (head) {
            if (head->val < tail->val) {
                //find inserting postion
                ListNode* small = dummy;
                while (small->next->val < head->val) {
                    small = small->next;
                }
                tail->next = head->next;
                head->next = small->next;
                small->next = head;
            } else {
                tail = head;
            }
            head = tail->next;
        }
        return dummy->next;
    }
};