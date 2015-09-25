/**
 * Something like quick sort.
 * Assume there is not duplicate.
 **/

class Solution {
public:
    // Iterative
    int findKthLargest(vector<int>& nums, int k) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            srand(time(nullptr));
            int mid = rand() % (end - begin + 1) + begin;
            
            // Partition the array and put the largers in the front
            swap(nums.at(begin), nums.at(mid));
            int i = begin + 1, j = end + 1;
            while (i < j) {
                if (nums.at(i) < nums.at(begin)) {
                    swap(nums.at(i), nums.at(j - 1));
                    --j;
                } else {
                    ++i;
                }
            }
            swap(nums.at(begin), nums.at(i - 1));
            
            if (i == k) {
                return nums.at(i - 1);
            } else if (i < k) {
                begin = i;
            } else {
                end = i - 2;
            }
        }
        return nums.at(begin);
    }
};
