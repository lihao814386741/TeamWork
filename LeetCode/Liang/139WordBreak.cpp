class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> DP(s.size() + 1, false);
        DP.at(0) = true;
        for (int i = 0; i < s.size(); ++i) {
            if (!DP.at(i)) {
                continue;
            }
            
            for (string str : wordDict) {
                if (s.substr(i, str.size()) == str) {
                    DP.at(i + str.size()) = true;
                }
            }
        }
        return DP.back();
    }
};
