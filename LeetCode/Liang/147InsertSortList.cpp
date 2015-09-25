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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *itr = head;
        while (itr) {
            ListNode *insert = itr;
            itr = itr->next;
            // Find insert position
            ListNode *tmpItr = dummy;
            while (tmpItr->next && tmpItr->next->val < insert->val) {
                tmpItr = tmpItr->next;    
            }
            insert->next = tmpItr->next;
            tmpItr->next = insert;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
