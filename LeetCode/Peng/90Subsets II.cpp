class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result(1, vector<int>());
        sort(nums.begin(), nums.end());
        int currentPos = 0;
        for (int i = 0; i < n; i++) {
            int current = nums.at(i);
            int sampleSize = result.size();
            int j = 0;
            if (i && nums.at(i) == nums.at(i - 1))
                j = currentPos;
            currentPos = result.size();
            for (; j < sampleSize; j++) {
                vector<int> subset = result.at(j);
                subset.push_back(current);
                result.push_back(subset);
            }
        }
        return result;
    }
};