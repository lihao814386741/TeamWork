public class Solution {
    int[][] direction = new int[][] {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    
    public boolean dfs(char[][] board, int x, int y, String word, int pos, boolean[][] isVisited) {
        if (pos == word.length()) {
            return true;
        }
        char c;
        try {
            c = board[x][y];
        }catch(Exception e) {
            return false;
        }
        
        if (c != word.charAt(pos)) {
            return false;
        }
        
        if (isVisited[x][y] == true) {
            return false;
        }
        isVisited[x][y] = true;
        
        for (int i = 0; i < direction.length; i ++) {
            if (dfs(board, x + direction[i][0], y + direction[i][1], word, pos + 1, isVisited) == true) {
                return true;
            }
        }
        
        isVisited[x][y] = false;
        return false;
    }
    
    
    
    public boolean exist(char[][] board, String word) {
        boolean[][] isVisited = new boolean[board.length][board[0].length];
        
        for (int i = 0; i < board.length; i ++) {
            for (int j = 0; j < board[i].length; j ++) {
                if (dfs(board, i, j, word, 0, isVisited) == true) {
                    return true;
                }
            }
        }
        
        return false;
    }
}
