class Solution {
public:
    int helper(vector<int>& nums, int begin, int end, int target) {
        if (begin > end) {
            begin = end == -1 ? begin : begin - 1;
            if (nums.at(begin) >= target)
                return begin;
            else
                return begin + 1;
        }
        
        int mid = begin + (end - begin) / 2;
        int current = nums.at(mid);
        if (current == target) return mid;
        else if (current > target)
            return helper(nums, begin, mid - 1, target);
        else
            return helper(nums, mid + 1, end, target);
    }
    int searchInsert(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};