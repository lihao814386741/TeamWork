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
    // Be careful [5] [5]
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *tail = dummy;
        int carry = 0;
        while (l1 || l2) {
            int num1 = 0, num2 = 0;
            if (l1) {
                num1 = l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                num2 = l2->val;
                l2 = l2->next;
            }
            
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            tail->next = newNode;
            tail = tail->next;
        }
        
        if (carry != 0) {
            ListNode *newNode = new ListNode(carry);
            tail->next = newNode;
            tail = tail->next;
        }
        
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};
