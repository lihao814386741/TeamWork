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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }
        
        int n = getLenth(head);
        k = k % n;
        if (k == 0) {
            return head;
        }
        
        int step = n - k - 1;
        ListNode *itr = head;
        while (step > 0) {
            --step;
            itr = itr->next;
        }
        
        ListNode *tail = itr;
        while (tail->next) {
            tail = tail->next;
        }
        
        tail->next = head;
        head = itr->next;
        itr->next = nullptr;
        return head;
    }
private:
    // Get the lenth of link list
    int getLenth(ListNode *head) {
        int lenth = 0;
        while (head) {
            ++lenth;
            head = head->next;
        }
        return lenth;
    }
};
