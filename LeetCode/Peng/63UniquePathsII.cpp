class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (!obstacleGrid.size() || !obstacleGrid.at(0).size()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        result.at(0).at(0) = obstacleGrid.at(0).at(0) ? 0 : 1;
        for (int i = 1; i < m; i++)
            if (!obstacleGrid.at(i).at(0))
                result.at(i).at(0) = result.at(i - 1).at(0);
        for (int i = 1; i < n; i++)
            if (!obstacleGrid.at(0).at(i))
                result.at(0).at(i) = result.at(0).at(i - 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid.at(i).at(j))
                    result.at(i).at(j) = 0;
                else
                    result.at(i).at(j) = result.at(i - 1).at(j) + result.at(i).at(j - 1);
            }
        }
        return result.at(m - 1).at(n - 1);
    }
};