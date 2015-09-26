class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (nums.at(mid) > nums.at(end)) {
                if (target <= nums.at(mid) && target > nums.at(end)) {
                    end = mid;
                } else {
                    begin = mid + 1;
                }
            } else {
                if (target <= nums.at(end) && target > nums.at(mid)) {
                    begin = mid + 1;
                } else {
                    end = mid;
                }
            }
        }
        
        if (nums.at(begin) == target) {
            return begin;
        } else {
            return -1;
        }
    }
};
