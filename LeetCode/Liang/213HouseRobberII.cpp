class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums.at(0);
        }
        
        int robFirst = robHelper(nums, 0, nums.size() - 2);
        int notRobFirst = robHelper(nums, 1, nums.size() - 1);
        return max(robFirst, notRobFirst);
    }
private:
    int robHelper(vector<int> &nums, int begin, int end) {
        assert(begin <= end);
        int maxLast = 0, maxLastLast = 0;
        for (int i = begin; i <= end; ++i) {
            int tmp = maxLast;
            maxLast = max(maxLast, maxLastLast + nums.at(i));
            maxLastLast = tmp;
        }
        return maxLast;
    }
};
