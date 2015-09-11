public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int rowMin = 0;
        int rowMax = n-1;
        int colMin = 0;
        int colMax = n-1;
        int num = 1;
        
        while(true) {
            for(int i=colMin; i<=colMax; i++) {
                result[rowMin][i] = num++;
            }
            if(num>n*n) return result;
            rowMin++;
            
            for(int i=rowMin; i<=rowMax; i++) {
                result[i][colMax] = num++;
            }
            if(num>n*n) return result;
            colMax--;
            
            for(int i=colMax; i>=colMin; i--) {
                result[rowMax][i] = num++;
            }
            if(num>n*n) return result;
            rowMax--;
            
            for(int i=rowMax; i>=rowMin; i--) {
                result[i][colMin] = num++;
            }
            if(num>n*n) return result;
            colMin++;
        }
    }
}