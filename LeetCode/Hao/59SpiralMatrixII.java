public class Solution {
    private int count = 1;
    private void loop (int[][] matrix, int from, int to, int c, boolean isInc, boolean isRow) {
        for (int i = from; isInc? i <= to : i >= to; i = isInc ? i +1 : i -1) {
            if (isRow == true) {
                matrix[c][i] = count;
                count ++;
            } else {
                matrix[i][c] = count;
                count ++;
            }
        }
    }

    public int[][] generateMatrix(int n) {
        int[][] matrix = new int [n][n];
    
        int colMin = 0;
        int colMax = n - 1;
        int rowMin = 0;
        int rowMax = n - 1;
        
        while (colMin <= colMax && rowMin <= rowMax) {
            loop (matrix, colMin, colMax, rowMin, true, true);
            rowMin ++;
            
            if (rowMin > rowMax) {
                break;
            }
            
            loop (matrix, rowMin, rowMax, colMax, true, false);
            colMax --;
            
            if (colMin > colMax) {
                break;
            }
            
            loop (matrix, colMax, colMin, rowMax, false, true);
            rowMax --;
            
            if (rowMin > rowMax) {
                break;
            }
            
            loop(matrix, rowMax, rowMin, colMin, false, false);
            colMin ++;
            
            if (colMin > colMax) {
                break;
            }
            
            
        }
        


        
        return matrix;
    }
}
