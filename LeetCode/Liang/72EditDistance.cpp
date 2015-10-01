/**
 * Special thanks to:
 * https://leetcode.com/discuss/50807/java-dp-solution-o-nm
 * If have time thing about these:
 * https://leetcode.com/discuss/42406/20ms-c-top-down-dp-solution
 **/
 
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> DP(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0) {
                    DP.at(i).at(j) = j;
                } else if (j == 0) {
                    DP.at(i).at(j) = i;
                } else {
                    if (word1.at(i - 1) == word2.at(j - 1)) { // Wrong to use word1.at(i);
                        DP.at(i).at(j) = DP.at(i - 1).at(j - 1);
                    } else {                 // insert             , delete                , replace
                        DP.at(i).at(j) = 1 + min(DP.at(i).at(j - 1), min(DP.at(i - 1).at(j), DP.at(i - 1).at(j - 1)));
                    }                      `
                }
            }
        }
        return DP.at(word1.size()).at(word2.size());
    }
};
