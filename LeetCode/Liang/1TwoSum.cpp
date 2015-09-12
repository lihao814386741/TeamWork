class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        assert(!nums.empty());
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums.at(i)) != hash.end()) {
                return {hash[nums.at(i)] + 1, i + 1};
            } else {
                hash[target - nums.at(i)] = i;
            }
        }
        // Cannot find it.
        return {-1, -1};
    }
};