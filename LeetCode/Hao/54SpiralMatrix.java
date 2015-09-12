public class Solution {
    private List<Integer> ans;

    private void loop(int[][] matrix, int from, int to, int c, boolean inc, boolean isRow) {
        for (int i = from; inc ? i <= to : i >= to ; i = inc? i+1 : i-1) {
            if (isRow == true) {
                ans.add(matrix[c][i]);   
            } else {
                ans.add(matrix[i][c]);
            }
        }
    }
    
    public List<Integer> spiralOrder(int[][] matrix) {
        ans = new ArrayList<Integer> ();
        
        if (matrix == null || matrix.length == 0) {
            return ans;    
        }
        
        int rowMin = 0;
        int rowMax = matrix.length - 1;
        int colMin = 0;
        int colMax = matrix[0].length - 1;

        while (rowMin <= rowMax && colMin <= colMax) {
            loop(matrix, colMin, colMax, rowMin, true, true);
            rowMin ++;
            
            if (rowMin > rowMax) {
                break;
            }
            
            loop(matrix, rowMin, rowMax, colMax, true, false);
            colMax --;
            
            if (colMin > colMax) {
                break;
            }
            
            loop(matrix, colMax, colMin, rowMax, false, true);
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
        
        return ans;
    }
}
