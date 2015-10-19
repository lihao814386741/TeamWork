/**
 * Try to communicate with this:
 * http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
 **/
 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (i == 0 && j == 0) {
                    dp.at(0).at(0) = true;
                } else if (i == 0) {
                    dp.at(0).at(j) = dp.at(0).at(j - 1) && s2[j - 1] == s3[j - 1];
                } else if (j == 0) {
                    dp.at(i).at(0) = dp.at(i - 1).at(0) && s1[i - 1] == s3[i - 1];
                } else {
                    dp.at(i).at(j) = (dp.at(i - 1).at(j) && s1[i - 1] == s3[i + j - 1]) || (dp.at(i).at(j - 1) && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};
