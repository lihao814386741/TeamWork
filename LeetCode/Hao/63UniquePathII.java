public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        
        int[] f = new int[n];
        f[0] = obstacleGrid[0][0] == 1? 0 : 1;
        
        for (int i = 0; i < m; i ++) {
            if (obstacleGrid[i][0] == 1) {
                f[0] = 0;
            }
            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] == 0) {
                    f[j] = f[j] + f[j - 1];
                } else {
                    f[j] = 0;
                }
            }
        }
        
        return f[n - 1];
    }
}
