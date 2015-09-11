public class Solution {
    public void setZeroes(int[][] matrix) {
        boolean vZero, hZero;
        
        vZero = hZero = false;
        
        for (int i = 0; i < matrix.length; i ++){
            if (matrix[i][0] == 0){
                vZero = true;
            }
        }
        for (int i = 0; i < matrix[0].length; i ++){
            if (matrix[0][i] == 0) {
                hZero = true;
            }
        }
        
        for (int i = 1; i < matrix.length; i ++) {
            for (int j = 1; j < matrix[i].length; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.length; i ++) {
            for (int j = 1; j < matrix[i].length; j ++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        if (vZero == true) {
            for (int i = 0; i < matrix.length; i ++) {
                matrix[i][0] = 0;
            }
        }
        if (hZero == true) {
            for (int i = 0; i < matrix[0].length; i ++) {
                matrix[0][i] = 0;
            }
        }
        
        
    }
}
