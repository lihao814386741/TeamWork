/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//1. Find the cycle
//2. Use a ptr starts from head, they will meet at the entry
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow != fast) return NULL;
        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};

//Hash map version
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> counter;
        while (head) {
            if (counter.count(head)) return head;
            counter[head] = 1;
            head = head->next;
        }
        return NULL;
    }
};