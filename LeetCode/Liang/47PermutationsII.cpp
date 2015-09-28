class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        
        unordered_set<int> hash;
        for (int i = step; i < nums.size(); ++i) {
            if (hash.find(nums.at(i)) != hash.end()) {
                continue;
            }
            
            hash.insert(nums.at(i));
            swap(nums.at(i), nums.at(step));
            permutationDFSHelper(nums, step + 1, result);
            swap(nums.at(i), nums.at(step));
        }
    }
};
