class Solution {
public:
    int numSquares(int n) {
        vector<int> DP(n + 1, INT_MAX);
        DP.at(0) = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                DP.at(i) = min(DP.at(i), DP.at(i - j * j) + 1);
            }
        }
        return DP.back();
    }
};
