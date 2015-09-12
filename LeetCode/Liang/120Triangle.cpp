class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        
        vector<int> DP = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle.at(i).size(); ++j) {
                DP.at(j) = min(DP.at(j), DP.at(j + 1)) + triangle.at(i).at(j);
            }
        }
        return DP.front();
    }
};
