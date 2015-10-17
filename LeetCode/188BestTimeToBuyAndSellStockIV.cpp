/**
 * Special thanks to:
 * 1. https://leetcode.com/discuss/62026/clean-java-dp-solution-with-comment
 **/
 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        // It means you can make the most profit transaction without care about the transaciton time.
        int globalMax = 0;
        if (k >= prices.size() / 2) {
            for (int i = 1; i < prices.size(); ++i) {
                if (prices.at(i) > prices.at(i - 1)) {
                    globalMax += prices.at(i) - prices.at(i - 1);
                }
            }
            return globalMax;
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; ++i) {
            int localMax = INT_MIN; // Here must be INT_MIN;
            for (int j = 1; j < prices.size(); ++j) { // j must cannot start from i. Because it's at most i transaction.
                // localMax = max(localMax, dp.at(i - 1).at(j - 1) - prices.at(j - 1) + prices.at(j)); // This is wrong.
                localMax = max(localMax, dp.at(i - 1).at(j - 1) - prices.at(j - 1));
                
                // maxPro can be calculated by localMax + prices.at(j);
                // int maxPro = 0;
                // for (int x = 1; x < j; ++x) {
                //     maxPro = max(maxPro, dp.at(i - 1).at(x) + prices.at(j) - prices.at(x));
                // } 
                
                dp.at(i).at(j) = max(prices.at(j) + localMax, dp.at(i).at(j - 1));
            }
        }
        return dp.back().back();
    }
};
