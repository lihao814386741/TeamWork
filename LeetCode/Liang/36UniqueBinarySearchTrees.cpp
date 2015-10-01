/**
 *  Assume that the result will not bigger than INT_MAX; 
 **/
 
class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        
        vector<int> DP(n + 1, 0); // Thought it's (n + 1) / 2 + 1;
        DP.at(0) = 1;
        DP.at(1) = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 0; j < i / 2; ++j) {
                DP.at(i) += DP.at(j) * DP.at(i - 1 - j);
            }
            
            DP.at(i) *= 2;
            if (i % 2) {
                DP.at(i) += DP.at(i / 2) * DP.at(i / 2);
            }
        }
        return DP.back();
    }
};
