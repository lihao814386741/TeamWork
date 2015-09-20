class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0, maxLen = 0;
        int sLen = s.size();
        bool *DP = new bool[sLen * sLen]();// TLE
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i) {
                    DP[i * sLen + j] = true;
                } else if (j == i - 1) {
                    DP[i * sLen + j] = (s[i] == s[j]);
                } else {
                    DP[i * sLen + j] = (s[i] == s[j] && DP[(i - 1) * sLen + j + 1]);
                }
                
                if (DP[i * sLen + j] && maxLen < i - j + 1) {
                    begin = j;
                    maxLen = i - j + 1;
                }
            }
        }
        delete[] DP; // MLE
        return s.substr(begin, maxLen);
    }
};
