class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix.at(0).size()) return;
        int m = matrix.size();
        int n = matrix.at(0).size();
        int firstRow = 1, firstColumn = 1;
        for (int i = 0; i < n; i++) {
            if (matrix.at(0).at(i) == 0) {
                firstRow = 0;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix.at(i).at(0) == 0) {
                firstColumn = 0;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix.at(i).at(j) == 0) {
                    matrix.at(0).at(j) = 0;
                    matrix.at(i).at(0) = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++){
                if (matrix.at(i).at(0) == 0 || matrix.at(0).at(j) == 0)
                    matrix.at(i).at(j) = 0;
            }
        }
        if (!firstRow) {
            for (int i = 0; i < n; i++)
                matrix.at(0).at(i) = 0;
        }
        if (!firstColumn) {
            for (int i = 0; i < m; i++)
                matrix.at(i).at(0) = 0;
        }
    }
};