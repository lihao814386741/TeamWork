public class Solution {
    public int searchInsert(int[] nums, int target) {
        int left, right;
        
        left = 0;
        right = nums.length - 1;
        
        while (left <= right) {
            if (left == right) {
                break;
            }
            
            int mid = left + (right - left) / 2;
            
            if (target == nums[mid]) {
                left = mid;
                break;
            } else if (target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if (target == nums[left]) {
            return left;
        } else if (target < nums[left]) {
            return left;
        } else {
            return left + 1;
        } 
        
    }
}
