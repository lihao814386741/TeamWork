/*
 * Iterative
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result(1, vector<int>());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int current = nums.at(i);
            int sampleSize = result.size();
            for (int j = 0; j < sampleSize; j++) {
                vector<int> subset = result.at(j);
                subset.push_back(current);
                result.push_back(subset);
            }
        }
        return result;
    }
};


/*
 * Recursive
 */
class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int> subset, vector<int>& nums, int steps) {
        if (!steps) {
            result.push_back(subset);
            return;
        }
        int n = nums.size();
        helper(result, subset, nums, steps - 1);
        subset.push_back(nums.at(n - steps));
        helper(result, subset, nums, steps - 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        helper(result, {}, nums, n);
        return result;
    }
};