/*
 * Iterative
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result(1, vector<int>());
        sort(nums.begin(), nums.end());
        int lastPos = 0;
        for (int i = 0; i < n; i++) {
            int current = nums.at(i);
            int sampleSize = result.size();
            int j = 0;
            if (i && nums.at(i) == nums.at(i - 1))
                j = lastPos;
            lastPos = result.size();
            for (; j < sampleSize; j++) {
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
    void helper(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int begin) {
        result.push_back(subset);
        int n = nums.size();
        for (int i = begin; i < n; i++) {
            subset.push_back(nums.at(i));
            helper(result, subset, nums, i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> subset = {};
        sort(nums.begin(), nums.end());
        helper(result, subset, nums, 0);
        return result;
    }
};
