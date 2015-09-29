class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        assert(n >= 1 && k >= 0);
        vector<int> path;
        vector<vector<int>> result;
        combineDFSHelper(1, n, k, path, result);
        return result;
    }
private:
    void combineDFSHelper(int start, int n, int step, vector<int> &path, vector<vector<int>> &result) {
        if (step == 0) {
            result.push_back(path);
            return;
        }
        
        for (int i = start; i <= n - step + 1; ++i) {
            path.push_back(i);
            combineDFSHelper(i + 1, n, step - 1, path, result);
            path.pop_back();
        }
    }
};
