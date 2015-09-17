class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> numCounter;
        for (int i = 0; i < n; i++) {
            int current = target - nums.at(i);
            if (numCounter.count(current)) {
                result.push_back(i + 1);
                result.push_back(numCounter[current] + 1);
                sort(result.begin(), result.end());
                break;
            }
            numCounter[nums.at(i)] = i;
        }
        return result;
    }
};