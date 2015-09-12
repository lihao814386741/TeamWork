public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new LinkedList<Integer>();
        if(matrix.length == 0) return result;    //corner case
        
        int rowMin = 0;
        int rowMax = matrix.length-1;
        int colMin = 0;
        int colMax = matrix[0].length-1;
        int count = (rowMax+1)*(colMax+1);
        
        while(true) {
            for(int i=colMin; i<=colMax; i++) {
                result.add(matrix[rowMin][i]);
                count--;
            }
            if(count == 0) break;
            rowMin++;
            
            for(int i=rowMin; i<=rowMax; i++) {
                result.add(matrix[i][colMax]);
                count--;
            }
            if(count == 0) break;
            colMax--;
            
            for(int i=colMax; i>=colMin; i--) {
                result.add(matrix[rowMax][i]);
                count--;
            }
            if(count == 0) break;
            rowMax--;
            
            for(int i=rowMax; i>=rowMin; i--) {
                result.add(matrix[i][colMin]);
                count--;
            }
            if(count == 0) break;
            colMin++;
        }
        return result;
    }
    
}