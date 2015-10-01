public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rowMax = matrix.length;
        if (rowMax == 0) {
            return 0;
        }
        int colMax = matrix[0].length;
        int[][] d = new int[rowMax][colMax];
        int max = 0;        
        
        for (int i = 0; i < rowMax; i ++) {
            for (int j = 0; j < colMax; j ++) {
                d[i][j] = matrix[i][j] == '1' ? 1 : 0;
            
                max = Math.max(max, d[i][j]);
            }
        }
        
        for (int i = 1; i < rowMax; i ++) {
            for (int j = 1; j < colMax; j ++) {
                if (matrix[i][j] == '1') {
                    d[i][j] = Math.min(d[i - 1][j - 1], Math.min(d[i - 1][j], d[i][j - 1])) + 1;
                } 
                max = Math.max(max, d[i][j]);
            }
        }
        
        return max * max;
    }
}
