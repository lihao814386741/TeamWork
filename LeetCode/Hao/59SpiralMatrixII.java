public class Solution {
    private final static int[][] direction = new int[][] {
        {0, 1}, // turn right
        {1, 0}, // turn down
        {0, -1}, // turn left
        {-1, 0} // turn up
    };
    
    private boolean isInBound(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int [n][n];
        int d = 0;
        int x = 0;
        int y = 0;
        int length = n * n;
        
        if (n == 0) {
            return matrix;
        }
        
        
        for (int i = 1; i <= length; i ++) {
            matrix[x][y] = i;
            
            for (int j = 0; j < 4; j ++) {
                int tmpx = x + direction[(d + j) % 4][0];
                int tmpy = y + direction[(d + j) % 4][1];
                
                if (isInBound(n, tmpx, tmpy) == true && matrix[tmpx][tmpy] == 0) {
                    d = (d + j) % 4;
                    x = tmpx;
                    y = tmpy;
                    
                    break;
                }
            }
        }
        
        return matrix;
    }
}
