/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/**
 * Try to use priority_queue to do it. And make it 
 **/
class Solution {
public:
    // Merge sort will not fit this. The time complexity is:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists, 0, (int)lists.size() - 1);
    }
private:
    ListNode *mergeKListsHelper(vector<ListNode*> &lists, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        
        if (begin == end) {
            return lists.at(begin);
        }
        
        // It seems that I forget this kind of process.
        int mid = begin + (end - begin) / 2;
        ListNode *left = mergeKListsHelper(lists, begin, mid);
        ListNode *right = mergeKListsHelper(lists, mid + 1, end);
        return mergeTwoSortedLists(left, right);
    }
    
    ListNode* mergeTwoSortedLists(ListNode *first, ListNode *second) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (first && second) {
            ListNode *tmp = nullptr;
            if (first->val < second->val) {
                tmp = first;
                first = first->next;
            } else {
                tmp = second;
                second = second->next;
            }
            
            tail->next = tmp;
            tail = tail->next;
        }
        tail->next = first ? first : second;
        first = dummy->next;
        delete dummy;
        return first;
    }
};
