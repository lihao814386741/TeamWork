public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0) return false;
        
        int rowLen = matrix.length;
        int colLen = matrix[0].length;
        int left = 0;
        int right = rowLen*colLen-1;
        
        while(left<right) {
            int mid = left + (right-left)/2;
            
            if(matrix[mid/colLen][mid%colLen] == target) return true;
            else if(matrix[mid/colLen][mid%colLen] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return matrix[left/colLen][left%colLen] == target;
    }
    
}