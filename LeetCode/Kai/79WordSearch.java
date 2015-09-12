public class Solution {
    public boolean exist(char[][] board, String word) {
        int row =  board.length;
        int col = board[0].length;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(existDFS(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    public boolean existDFS(char[][] board, int i, int j, String word, int k) {
        //condition to return
        if(k == word.length()) return true;
        if( i<0 || j<0 || i==board.length || j==board[0].length || board[i][j]!=word.charAt(k)) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        boolean exist = existDFS(board, i-1, j, word, k+1)
                        ||existDFS(board, i+1, j, word, k+1)
                        ||existDFS(board, i, j-1, word, k+1)
                        ||existDFS(board, i, j+1, word, k+1);
        board[i][j] = temp;
        return exist;
    }
    
}