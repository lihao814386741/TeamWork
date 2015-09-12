class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Use DFSHelper();
        vector<int> path;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        DFSHelper(nums, 0, path, result);
        return result;
    }
    
private:
    // There are at most 2^n subset and push_back will cost at most n. Therefore, is O(n * 2^n); 
    void DFSHelper(vector<int> &nums, int step, vector<int> &path, vector<vector<int>> &result) {
        if (step == nums.size()) {
            result.push_back(path);
            return;
        }
        
        // Do not choose anything
        result.push_back(path);
        
        for (int i = step; i < nums.size(); ++i) {
            if (i == step || nums.at(i) != nums.at(i - 1)) {
                path.push_back(nums.at(i));
                DFSHelper(nums, i + 1, path, result);
                path.pop_back();
            }
        }
    }
};
