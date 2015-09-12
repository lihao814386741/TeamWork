class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }
        
        int row = matrix.size();
        int column = matrix.at(0).size();
        int loop = row <= column ? (row - 1) / 2 : (column - 1) / 2;
        vector<int> result;
        for (int k = 0; k <= loop; ++k) {
            // Top
            for (int j = k; j < column - k; ++j) {
                result.push_back(matrix.at(k).at(j));
            }
            
            // Right
            for (int i = k + 1; i < row - k; ++i) {
                result.push_back(matrix.at(i).at(column - k - 1));
            }
            
            // Bottom: if bottom row is not equal to top row;
            if (row - k - 1 != k) {
                for (int j = column - k - 2; j > k; --j) {
                    result.push_back(matrix.at(row - k - 1).at(j));
                } 
            }
            
            
            // Left: if left column is not equal to right column
            if (column - k - 1 != k) {
                for (int i = row - k - 1; i > k; --i) {
                    result.push_back(matrix.at(i).at(k));
                }   
            }
        }
        
        return result;
    }
};
