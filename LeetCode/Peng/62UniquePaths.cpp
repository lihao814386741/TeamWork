class Solution {
public:
    int uniquePaths(int m, int n) {
        if (!m || !n) return 0;
        vector<vector<int>> result(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                result.at(i).at(j) = result.at(i - 1).at(j) + result.at(i).at(j - 1);
            }
        }
        return result.at(m - 1).at(n - 1);
    }
};