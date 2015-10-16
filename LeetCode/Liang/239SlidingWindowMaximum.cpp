class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> indexQue;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            while (!indexQue.empty() && nums[indexQue.back()] <= nums[i]) indexQue.pop_back();
            indexQue.push_back(i);
            if (i - indexQue.front() + 1 > k) indexQue.pop_front();
            
            if (i >= k - 1 && !indexQue.empty()) {
                result.push_back(nums.at(indexQue.front()));
            }
        }
        return result;
    }
};
