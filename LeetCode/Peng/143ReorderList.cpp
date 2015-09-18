/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Use List is straightforward.
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* dummy = new ListNode(-1);
        list<ListNode*> nodes;
        ListNode* current = head;
        while (current) {
            nodes.push_back(current);
            current = current->next;
        }
        current = dummy;
        int n = nodes.size();
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                current->next = nodes.front();
                nodes.pop_front();
            } else {
                current->next = nodes.back();
                nodes.pop_back();
            }
            current = current->next;
        }
        current->next = NULL;
    }
};

//Reverse the second half of list
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* current = head->next;
        ListNode* next = current->next;
        head->next = NULL;
        current->next = head;
        while (next) {
            head = current;
            current = next;
            next = next->next;
            current->next = head;
        }
        return current;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* slow = head, * fast = head;
        while (fast->next  && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverseList(slow->next);
        slow->next = NULL;
        slow = head;
        ListNode* dummy = new ListNode(-1);
        head = dummy;
        while (slow && fast) {
            head->next = slow;
            slow = slow->next;
            head = head->next;
            head->next = fast;
            head = head->next;
            fast = fast->next;
        }
        head->next = slow;
        head = dummy->next;
    }
};