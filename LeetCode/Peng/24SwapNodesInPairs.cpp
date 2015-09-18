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
    ListNode* swapPairs(ListNode* head) {
       if (!head || !head->next) return head;
       ListNode* result = head->next;
       ListNode* last = NULL;
       while (head && head->next) {
           ListNode* temp = head->next;
           head->next = temp->next;
           temp->next = head;
           if (!last) {
               last = head;
           } else {
               last->next = temp;
               last = head;
           }
           head = head->next;
       }
       return result;
    }
}; 

//recursive version
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if (!head || !head->next) return head;
       ListNode* temp = head->next;
       head->next = swapPairs(temp->next);
       temp->next = head;
       return temp;
    }
};