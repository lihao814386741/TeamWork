/**
 * Dp
 **/

class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m > 0 && n > 0);
        vector<int> DP(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                DP.at(j) = DP.at(j) + DP.at(j - 1);
            }
        }
        return DP.back();
    }
};