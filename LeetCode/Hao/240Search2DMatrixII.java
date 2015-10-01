public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rowMax = matrix.length;
        int colMax = matrix[0].length;
        int i = rowMax - 1;
        int j = 0;
        
        while (j < colMax && i >= 0) {
            if (matrix[i][j] < target) {
                j ++;
            } else if (matrix[i][j] > target) {
                i --;
            } else {
                return true;
            }
        }
        
        return false;
    }
}
