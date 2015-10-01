class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int maxLen = 0;
        vector<vector<int>> DP(matrix.size(), vector<int>(matrix.at(0).size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.at(0).size(); ++j) {
                if (matrix.at(i).at(j) == '1') {
                    if (i == 0 || j == 0) {
                        DP.at(i).at(j) = 1;
                    } else {
                        DP.at(i).at(j) = min(DP.at(i).at(j - 1), min(DP.at(i - 1).at(j), DP.at(i - 1).at(j - 1))) + 1;
                    }
                    maxLen = max(maxLen, DP.at(i).at(j)); 
                }
            }
        }
        return maxLen * maxLen;
    }
};
