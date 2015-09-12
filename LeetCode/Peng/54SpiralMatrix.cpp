class Solution {
public:
    enum Directions : int {RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3};
    void helper(vector<int>& result, vector<vector<int>>& matrix, unordered_map<string, int>& limits) {
        int direct = RIGHT;
        int row = 0, column = 0;
        while (limits["up"] <= limits["down"] && limits["left"] <= limits["right"]) {
            if (direct == RIGHT) {
                while (column <= limits["right"]) {
                    result.push_back(matrix.at(row).at(column));
                    column++;
                }
                column--;
                row++;
                limits["up"]++;
                
            } else if (direct == DOWN) {
                while (row <= limits["down"]) {
                    result.push_back(matrix.at(row).at(column));
                    row++;
                }
                row--;
                column--;
                limits["right"]--;
            } else if (direct == LEFT) {
                while (column >= limits["left"]) {
                    result.push_back(matrix.at(row).at(column));
                    column--;
                }
                column++;
                row--;
                limits["down"]--;
            } else if (direct == UP) {
                while (row >= limits["up"]) {
                    result.push_back(matrix.at(row).at(column));
                    row--;
                }
                row++;
                column++;
                limits["left"]++;
            } 
            direct = (direct + 1) % 4;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (!matrix.size() || !matrix.at(0).size()) return result;
        int m = matrix.size();
        int n = matrix.at(0).size();
        unordered_map<string, int> limits = {{"up", 0}, {"down", m - 1}, {"left", 0}, {"right", n - 1}};
        helper(result, matrix, limits);
        return result;
    }
};