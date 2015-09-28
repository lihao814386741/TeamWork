class Solution {
public:
    // It doesn't have 
    vector<vector<int>> permute(vector<int>& nums) {
        // Sorted first
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permutationDFSHelper(nums, 0, result);
        return result;
    }
private:
    void permutationDFSHelper(vector<int> &nums, int step, vector<vector<int>> &result) {
        if (step >= (int)nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        
        for (int i = step; i < nums.size(); ++i) {
            if (i != step && nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            
            swap(nums.at(i), nums.at(step));
            permutationDFSHelper(nums, step + 1, result);
            swap(nums.at(i), nums.at(step));
        }
    }
};
