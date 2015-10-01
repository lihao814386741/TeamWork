class Solution {
public:
    int numDecodings(string s) {
        // Special case.
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        vector<int> DP(s.size() + 1);
        DP.at(0) = 1;
        DP.at(1) = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    DP.at(i + 1) = DP.at(i - 1);
                } else {
                    return 0;
                }
            } else {
                if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] < '7')) {
                    DP.at(i + 1) = DP.at(i) + DP.at(i - 1);
                } else {
                    DP.at(i + 1) = DP.at(i);
                }
            }
        }
        return DP.back();
    }
};
