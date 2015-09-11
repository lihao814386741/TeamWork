class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (target <= nums.at(mid)) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        
        if (target > nums.at(begin)) {
            ++begin;
        }
        
        return begin;
    }
};
