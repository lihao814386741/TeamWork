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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Special case.
        if (k <= 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *pre = dummy, *tail = dummy->next; // tail need * in front.
        while (true) {
            int counter = k;
            while (counter > 1 && tail) { // // I did something wrong here. Bigger than 1;
                tail = tail->next;
                --counter;
            }
            
            if (counter >= 1 && !tail) break; // I did something wrong here.
            
            ListNode *tmp = tail->next;
            reverseGroup(pre->next, tail);
            pre = tail;
            pre->next = tmp;
            tail = pre->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
    
private:
    // Assume that the function can only deal with k >= 1;
    void reverseGroup(ListNode *&head, ListNode *&tail) {
        // Head insert.
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *stop = tail->next;
        tail = head;
        while (head != stop) { // I did something wrong here.
            ListNode *tmp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = tmp;
        }
        head = dummy->next;
        delete dummy;
    }
};
