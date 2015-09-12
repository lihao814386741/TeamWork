class Solution {
public:
    int helper(vector<int>& nums, int begin, int end, int target, int left) {
        if (begin > end) return -1;
        
        int mid = begin + (end - begin) / 2;
        int current = nums.at(mid);
        if (current < target)
            return helper(nums, mid + 1, end, target, left);
        else if (current > target)
            return helper(nums, begin, mid - 1, target, left);
        else {
            int index;
            if (left) 
                index =  helper(nums, begin, mid - 1, target, left);
            else
                index = helper(nums, mid + 1, end, target, left);
            return index == -1 ? mid: index;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        result.push_back(helper(nums, 0, n - 1, target, 1));
        result.push_back(helper(nums, 0, n - 1, target, 0));
        return result;
    }
};