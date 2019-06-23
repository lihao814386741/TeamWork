/**
 * Special thanks to:
 * 1. https://leetcode.com/discuss/61415/share-my-clean-solution-based-on-valid-sudoku
 * It's a very wired kind of backtrack. It's a little different from my DFS.
 * Interesting. It's really hard to debug this code. 
 **/
 
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        assert(board.size() == 9 && board.at(0).size() == 9);
        generateGraph(board);
        solveSudokuDFSHelper(board);
    }
private:
    bool row[9][9];
    bool col[9][9];
    bool block[9][9];
    
    void generateGraph(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board.at(i).at(j) == '.') {
                    continue;
                }

                int k = 3 * (i / 3) + j / 3; // Get the corresponding block that (x, y) belongs to.
                int index = board.at(i).at(j) - '0' - 1;
                row[i][index] = true;
                col[j][index] = true;
                block[k][index] = true;
            }
        }
    }
    
    // This is my own understanding of backtrack. It's faster than the blog one
    bool solveSudokuDFSHelperII(vector<vector<char>> &board, int counter) {
        if (counter == 80) {
            return true;
        }
        
        int i = counter / 9;
        int j = counter % 9;
        int k = 3 * (i / 3) + j / 3;
        
        if (board.at(i).at(i) != '.') {
            return solveSudokuDFSHelperII(board, counter + 1);
        }
        
        // Test each number from 1 to 9
        for (int l = 1; l <= 9; ++l) {
            if (row[i][l - 1] || col[j][l - 1] || block[k][l - 1]) {
                continue;
            }
                    
            row[i][l - 1] = true;
            col[j][l - 1] = true;
            block[k][l - 1] = true;
            board.at(i).at(j) = '0' + l;
                    
            if (solveSudokuDFSHelperII(board, counter + 1)) return true;
                    
            row[i][l - 1] = false;
            col[j][l - 1] = false;
            block[k][l - 1] = false;
        }
        
        // when all 1 to 9 is not suitable.
        board.at(i).at(j) = '.';
        return false;
    }
    
    bool solveSudokuDFSHelper(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board.at(i).at(j) != '.') {
                    continue;
                }
                
                int k = 3 * (i / 3) + j / 3;
                
                // Test each number from 1 to 9
                for (int l = 1; l <= 9; ++l) {
                    if (row[i][l - 1] || col[j][l - 1] || block[k][l - 1]) {
                        continue;
                    }
                    
                    row[i][l - 1] = true;
                    col[j][l - 1] = true;
                    block[k][l - 1] = true;
                    board.at(i).at(j) = '0' + l;
                    
                    if (solveSudokuDFSHelper(board)) return true;
                    
                    row[i][l - 1] = false;
                    col[j][l - 1] = false;
                    block[k][l - 1] = false;
                }
                // when all 1 to 9 is not suitable.
                board.at(i).at(j) = '.';
                return false;
            }
        }
        return true; // When all is not '.';
    }
};
