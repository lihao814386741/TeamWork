class Solution {
public:
    int candy(vector<int>& ratings) {
        // Special case.
        if (ratings.size() < 2) {
            return ratings.size();
        }
        
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings.at(i) > ratings.at(i - 1)) {
                candy.at(i) = candy.at(i - 1) + 1;
            }
        }
        
        for (int i = ratings.size() - 2; i >= 0; --i) { // Not ++i; Be careful.
            if (ratings.at(i) > ratings.at(i + 1)) {
                candy.at(i) = max(candy.at(i), candy.at(i + 1) + 1);
            }
        }
        
        int result = 0;
        for (int i = 0; i < candy.size(); ++i) {
            result += candy.at(i);
        }
        return result;
    }
};
