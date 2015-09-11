/**
 * Use DP: DP[i]: all the subset of [0...i];
 **/
 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1, vector<int>());
        for (int i = 0; i < nums.size(); ++i) {
            int currentSize = result.size();
            for (int j = 0; j < currentSize; ++j) {
                vector<int> tmp = result.at(j);
                tmp.push_back(nums.at(i));
                result.push_back(tmp);
            }
        }
        return result;
    }
};
