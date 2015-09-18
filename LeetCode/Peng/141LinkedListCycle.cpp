/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Fast & slow ptr version
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

//Hash map version
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> counter;
        while (head) {
            if (counter.count(head)) return true;
            counter[head] = 1;
            head = head->next;
        }
        return false;
    }
};