public class Solution {
    
    private boolean checkLine(char[][] board, boolean isRow){
        for (int i = 0; i < board.length; i ++) {
            Map<Character, Boolean> hmap = new HashMap<Character, Boolean> ();
            for (int j = 0; j < board[i].length; j ++) {
                char c;
                if (isRow == true) {
                    c = board[i][j];
                } else {
                    c = board[j][i];
                }
                if (c != '.' && hmap.containsKey(c) == true) {
                    return false;
                } else if (c != '.') {
                    hmap.put(c, true);
                }
                
            }
        }
        
        return true;
    }
    
    private boolean checkSmallBox(char[][] board, int row, int col){
        Map<Character, Boolean> hmap = new HashMap<Character, Boolean> ();
        
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                char c = board[row + i][col + j];
                if (c != '.' && hmap.containsKey(c) == true) {
                    return false;
                } else if (c != '.') {
                    hmap.put(c, true);
                }
            }
        }
        
        return true;
    }
    
    private boolean checkBlock(char[][] board) {
        for (int i = 0; i < board.length; i += 3) {
            for (int j = 0; j < board[0].length; j += 3) {
                if (checkSmallBox(board, i, j) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    
    public boolean isValidSudoku(char[][] board) {
        if (checkLine(board, true) == false || checkLine(board, false) == false) {
            return false;
        }
        
        return checkBlock(board);
    }
}
