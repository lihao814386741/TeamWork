#define MARK '#'

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Special case
        if (word.empty()) {
            return true;
        }
        
        if (board.empty()) {
            return false;
        }
        
        int row = board.size();
        int column = board.at(0).size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (DFSHelper(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    // Check empty before use this function.
    bool DFSHelper(vector<vector<char>> &board, int x, int y, const string &word, int current) {
        assert(!board.empty());
        
        // Base case
        if (word.at(current) != board.at(x).at(y)) {
            return false;
        }
        
        if (current == word.size() - 1) {
            return true;
        }
        
        int row = board.size();
        int column = board.at(0).size();
        
        // Mark the board
        char originalChar = board.at(x).at(y);
        board.at(x).at(y) = MARK;
        
        if (x < row - 1 && board.at(x + 1).at(y) != MARK && DFSHelper(board, x + 1, y, word, current + 1)) {
            board.at(x).at(y) = originalChar;
            return true;
        }
        
        if (y < column - 1 && board.at(x).at(y + 1) != MARK && DFSHelper(board, x, y + 1, word, current + 1)) {
            board.at(x).at(y) = originalChar;
            return true;
        }
        
        if (x > 0 && board.at(x - 1).at(y) != MARK && DFSHelper(board, x - 1, y, word, current + 1)) {
            board.at(x).at(y) = originalChar;
            return true;
        }
        
        if (y > 0 && board.at(x).at(y - 1) != MARK && DFSHelper(board, x, y - 1, word, current + 1)) {
            board.at(x).at(y) = originalChar;
            return true;
        }
        
        // Retrun originalChar;
        board.at(x).at(y) = originalChar;
        return false;
    }
};