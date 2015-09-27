public class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        
        for(int i=0; i<Math.ceil((double)n/2); i++) { //one quarter. Row or Column(not both) should contain the rounded elements
            for(int j=0; j<n/2; j++) {
                int tmp = matrix[i][j];    //(i,j) -> (j,n-1-i) -> (n-1-i,n-1-j) -> (n-1-j,i) -> (i,j)
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
    
}