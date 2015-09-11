class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        
        int row = matrix.size();
        int column = matrix.at(0).size();
        
        // Mark to the first column and first row
        bool firstRow = false;
        bool firstCol = false;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (i == 0 && j == 0 && matrix.at(0).at(0) == 0) {
                    firstRow = true;
                    firstCol = true;
                } else if (i == 0 && matrix.at(0).at(j) == 0) {
                    firstRow = true;
                } else if (j == 0 && matrix.at(i).at(0) == 0) {
                    firstCol = true;
                } else if (matrix.at(i).at(j) == 0) {
                    matrix.at(i).at(0) = 0;
                    matrix.at(0).at(j) = 0;
                }
                cout << matrix.at(0).at(0);
            }
        }
        
        // Change to zero
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < column; ++j) {
                if (matrix.at(i).at(0) == 0 || matrix.at(0).at(j) == 0) {
                    matrix.at(i).at(j) = 0;
                }
            }
        }
        
        // Special first column and first row
        if (firstCol) {
            for (int i = 0; i < row; ++i) {
                matrix.at(i).at(0) = 0;
            }
        }
        
        if (firstRow) {
            for (int j = 0; j < column; ++j) {
                matrix.at(0).at(j) = 0;
            }
        }
    }
};
