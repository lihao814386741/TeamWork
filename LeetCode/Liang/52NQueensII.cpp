class Solution {
public:
    int totalNQueens(int n) {
        _size = n;
        totalNQueensHelper(n, 0);
        return _result;
    }
    
private:
    void totalNQueensHelper(const int n, int row) {
        if (row == n) {
            ++_result;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (!isValid(row, col)) {
                continue;
            }
            
            mark(row, col);
            totalNQueensHelper(n, row + 1);
            reverseMark(row, col);
        }
    }
    
    int _column = 0;
    int _diagonal = 0;
    int _rdiagonal = 0;
    int _size = 0;
    int _result = 0;
    
    bool isValid(const int &x, const int &y) {
        return ((_column & (1 << y)) || (_diagonal & (1 << (_size - 1 + x - y))) || (_rdiagonal & (1 << (x + y)))) == 0;
    }
    
    void mark(const int &x, const int &y) {
        _column |= 1 << y;
        _diagonal |= 1 << (_size - 1 + x - y);
        _rdiagonal |= 1 << (x + y);
    }
    
    void reverseMark(const int &x, const int &y) {
        _column &= ~(1 << y);
        _diagonal &= ~(1 << (_size - 1 + x - y));
        _rdiagonal &= ~(1 << (x + y));
    }
};
