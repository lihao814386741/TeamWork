/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Carefully to deal with the carry
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        int scale = 10;
        int one, two, carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        while (l1 || l2) {
            one = 0;
            two = 0;
            if (l1) {
                one = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                two = l2->val;
                l2 = l2->next;
            }
            int value = one + two + carry;
            carry = value / scale;
            value = value % scale;
            current->next = new ListNode(value);
            current = current->next;
        }
        if (carry) {
            current->next = new ListNode(1);
        }
        return dummy->next;
    }
};