public class Solution {
    
    private final static int[][] direction = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    private boolean isInBound(int colMax, int rowMax, int x, int y) {
        return x >= 0 && x < colMax && y >= 0 && y < rowMax;
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<Integer> ();
        
        if (matrix == null || matrix.length == 0) {
            return ans;
        }
        
        boolean[][] isVisited = new boolean[matrix.length][matrix[0].length];
        int d = 0;
        int x = 0;
        int y = 0;
        
        int length = matrix.length * matrix[0].length;
        
        for (int i = 0; i < length; i ++) {
            ans.add(matrix[x][y]);
            
            for (int j = 0; j < 4; j ++) {
                int tmpx = x + direction[(d + j) % 4][0];
                int tmpy = y + direction[(d + j) % 4][1];
                
                if (isInBound(matrix.length, matrix[0].length, tmpx, tmpy) && isVisited[tmpx][tmpy] == false) {
                    isVisited[tmpx][tmpy] = true;
                    x = tmpx;
                    y = tmpy;
                    d = (d + j) % 4;
                    
                    break;
                }
            }
        }
        
        
        return ans;
        
        
        
    }
}
