class Solution {
public:
    enum Directions : int {RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3};
    void helper(vector<vector<int>>& result, unordered_map<string, int>& limits) {
        int direct = RIGHT;
        int row = 0, column = 0;
        int count = 1;
        while (limits["up"] <= limits["down"] && limits["left"] <= limits["right"]) {
            if (direct == RIGHT) {
                while (column <= limits["right"]) {
                    result.at(row).at(column) = count;
                    column++;
                    count++;
                }
                column--;
                row++;
                limits["up"]++;
                
            } else if (direct == DOWN) {
                while (row <= limits["down"]) {
                    result.at(row).at(column) = count;
                    row++;
                    count++;
                }
                row--;
                column--;
                limits["right"]--;
            } else if (direct == LEFT) {
                while (column >= limits["left"]) {
                    result.at(row).at(column) = count;
                    column--;
                    count++;
                }
                column++;
                row--;
                limits["down"]--;
            } else if (direct == UP) {
                while (row >= limits["up"]) {
                    result.at(row).at(column) = count;
                    row--;
                    count++;
                }
                row++;
                column++;
                limits["left"]++;
            } 
            direct = (direct + 1) % 4;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        unordered_map<string, int> limits = {{"up", 0}, {"down", n - 1}, {"left", 0}, {"right", n - 1}};
        helper(result, limits);
        return result;
    }
};