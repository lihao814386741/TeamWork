class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> grid(n, vector<int>(n, 1));
        int count = 0, row = n, column = n;
        for (int k = 0; k <= (n - 1) / 2; ++k) {
            // Top: Here cannot be j < column - k - 1; it will cause the last one element cannot be assign value; 
            for (int j = k; j < column - k; ++j) grid.at(k).at(j) = ++count;
            // Right
            for (int i = k + 1; i < row - k - 1; ++i) grid.at(i).at(column - k - 1) = ++count;
            // Bottom
            for (int j = column - k - 1; j > k; --j) grid.at(row - k - 1).at(j) = ++count;
            // Left
            for (int i = column - k - 1; i > k; --i) grid.at(i).at(k) = ++count;
        }
        return grid;
    }
};
