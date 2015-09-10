public class Solution {
    private int findEle(int[] nums, int target, int method) {
        int left, right;
        left = 0;
        right = nums.length - 1;
        
        while (left <= right) {
            if (left == right) {
                break;
            }
            
            int mid = left + (right - left) / 2;
            
            if (target == nums[mid]) {
                if (method == 0){
                    left = mid;
                    break;
                } else if (method == 1) { // find left.
                    right = mid;
                } else { // find right.
                    left = mid + 1;
                }
                
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (method == 0 && nums[left] != target) {
            return -1;
        } else if (method == 1 && nums[left] < target) {
            return left + 1;
        } else if (method == 2 && nums[right] > target) {
            return left - 1;
        }
        
        return left;
    }
    
    public int[] searchRange(int[] nums, int target) {
        int[] position = new int[2];
        position[0] = position[1] = -1;
        
        if (nums == null || nums.length == 0){
            return position;
        }
    
        if (findEle(nums, target, 0) == -1) {
            return position;
        }
        position[0] = findEle(nums, target, 1);
        position[1] = findEle(nums, target, 2);
        return position;
    }
}
