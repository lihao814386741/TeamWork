/**
 * Special thanks to:
 * Java: https://leetcode.com/discuss/56815/o-n-java-solution-using-o-n-space
 **/
 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }
        
        // helper.at(i): @index means citation i @value means number of paper have at least citation i
        // This method is really good. And worth to make some conclusion.
        int n = citations.size();
        vector<int> helper(n + 1, 0);
        
        // Step 1: calculate how many paper have exactlly citation i;
        for (int i = 0; i < citations.size(); ++i) {
            if (citations.at(i) >= n) {
                ++helper.at(n);
            } else {
                ++helper.at(citations.at(i));
            }
        }
        
        // Step 2: calculate the helper.at(i)
        if (helper.at(n) >= n) return n;
        
        for (int i = n - 1; i >= 0; --i) {
            helper.at(i) += helper.at(i + 1);
            if (helper.at(i) >= i) {
                return i;
            }
        }
        
        return 0;
    }
};
