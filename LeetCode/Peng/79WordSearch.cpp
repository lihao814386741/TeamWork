class Solution {
public:
    bool checkValidation(vector<vector<char>>& board, vector<vector<char>>& visited, int row, int column) {
        if (row < 0 || row >= board.size() || column < 0 || column >= board.at(0).size() || visited.at(row).at(column) == '#' ) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<char>>& visited, vector<vector<int>>& direct, int row, int column, string& word, int pos) {
        if (!checkValidation(board, visited, row, column) || board.at(row).at(column) != word.at(pos)) return false;
        if (pos == word.size() - 1) return true;
        
        visited.at(row).at(column) = '#';
        for (int i = 0; i < direct.size(); i++) {
            if (dfs(board, visited, direct, row + direct.at(i).at(0), column + direct.at(i).at(1), word, pos + 1))
                return true;
        }
        visited.at(row).at(column) = 'v';
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size() || !board.at(0).size()) return false;
        int row = board.size();
        int column = board.at(0).size();
        char start = word.at(0);
        vector<vector<char>> visited(row, vector<char>(column, 'v'));
        vector<vector<int>> direct = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if ((board.at(i).at(j) == start) && dfs(board, visited, direct, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};