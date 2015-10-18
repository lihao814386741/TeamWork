/**
 * The trick is from the end to the start using DP.
 **/
 
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon.at(0).empty()) {
            return 0;
        }
        
        vector<int> dp(dungeon.at(0).size(), INT_MAX);
        int row = dungeon.size();
        int column = dungeon.at(0).size();
        for (int i = row - 1; i >= 0; --i) {
            for (int j = column - 1; j >= 0; --j) {
                if (i == row - 1 && j == column - 1) {
                    dp.at(j) = max(1, 1 - dungeon.at(i).at(j));
                } else if (i == row - 1) {
                    dp.at(j) = max(1, dp.at(j + 1) - dungeon.at(i).at(j));
                } else if (j == column - 1) {
                    dp.at(j) = max(1, dp.at(j) - dungeon.at(i).at(j));
                } else {
                    dp.at(j) = max(1, min(dp.at(j), dp.at(j + 1)) - dungeon.at(i).at(j));
                }
            }
        }
        return dp.at(0);
    }
};
