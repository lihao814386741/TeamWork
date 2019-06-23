/**
 * My original hash method lead to TLE;
 * So use the bitmap:
 * https://leetcode.com/discuss/56417/20-line-4ms-c-solution-using-bitmap
 * The limitation is that it can only support n <= 64;
 **/
 
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        assert(n > 0);
        _size = n;
        vector<string> solution(n, string(n, '.'));
        vector<vector<string>> solutionSpace;
        solveNQueensHelper(n, 0, solution, solutionSpace);
        return solutionSpace;
    }
private:
    // DFS the whole solution space.
    void solveNQueensHelper(const int n, int row, vector<string> &solution, vector<vector<string>> &solutionSpace) {
        // Base case.
        if (row == n) {
            // Add the path to the solution space.
            solutionSpace.push_back(solution);
            return;
        }
        
        // Traverse each column and if the column is good. Recursively solve the problem in the next row.
        for (int j = 0; j < n; ++j) {
            if (!isValid(row, j)) {
                continue;
            }
            
            solution.at(row).at(j) = 'Q';
            mark(row, j);
            solveNQueensHelper(n, row + 1, solution, solutionSpace);
            solution.at(row).at(j) = '.';
            reverseMark(row, j);
        }
    }
    
    int columnBit = 0;
    int diagonal = 0;
    int rdiagonal = 0;
    int _size = 0;
    
    // @return whether (x, y) slot is valid.
    bool isValid(const int &x, const int &y) {
        return ((columnBit & (1 << y)) || (diagonal & (1 << (_size - 1 + x - y))) || (rdiagonal & (1 << (x + y)))) == 0;  
    }
    
    // Mark col, diagoal, rdiagonal when choose (x, y);
    void mark(const int &x, const int &y) {
        columnBit |= 1 << y;
        diagonal |= 1 << (_size - 1 + x - y);
        rdiagonal |= 1 << (x + y);
    }
    
    // reverse mark when don't choose (x, y);
    void reverseMark(const int &x, const int &y) {
        columnBit &= ~(1 << y);
        diagonal &= ~(1 << (_size - 1 + x - y));
        rdiagonal &= ~(1 << (x + y));
    }
};
