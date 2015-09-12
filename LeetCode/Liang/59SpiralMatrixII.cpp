class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int count = 0;
        int rowMin = 0, rowMax = n - 1, colMin = 0, colMax = n - 1;
        while (rowMin <= rowMax && colMin <= colMax) {
            for (int j = colMin; j <= colMax; ++j) {
                grid.at(rowMin).at(j) = ++count;
            }
            ++rowMin;
            
            for (int i = rowMin; i <= rowMax; ++i) {
                grid.at(i).at(colMax) = ++count;
            }
            --colMax;
            
            for (int j = colMax; j >= colMin; --j) {
                grid.at(rowMax).at(j) = ++count;
            }
            --rowMax;
            
            for (int i = rowMax; i >= rowMin; --i) {
                grid.at(i).at(colMin) = ++count;
            }
            ++colMin;
        }
        return grid;
    }
};