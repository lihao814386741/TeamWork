class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }
        
        int rowMin = 0;
        int rowMax = (int)matrix.size() - 1;
        int colMin = 0;
        int colMax = (int)matrix.at(0).size() - 1;
        
        vector<int> result;
        while (rowMin <= rowMax && colMin <= rowMax) {
            // Top
            for (int j = colMin; j <= colMax; ++j) {
                result.push_back(matrix.at(rowMin).at(j));
            }
            ++rowMin;
            if (rowMin > rowMax) break;
            
            // Right
            for (int i = rowMin; i <= rowMax; ++i) {
                result.push_back(matrix.at(i).at(colMax));
            }
            --colMax;
            if (colMin > colMax) break;
            
            // Bottom: if bottom row is not equal to top row;
            for (int j = colMax; j >= colMin; --j) {
                result.push_back(matrix.at(rowMax).at(j));
            }
            --rowMax;
            if (rowMin > rowMax) break;
            
            // Left: if left column is not equal to right column
            for (int i = rowMax; i >= rowMin; --i) {
                result.push_back(matrix.at(i).at(colMin));
            }
            ++colMin;
            if (colMin > colMax) break;
        }
        
        return result;
    }
};