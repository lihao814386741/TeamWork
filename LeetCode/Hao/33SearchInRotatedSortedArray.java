public class Solution {
    public int search(int[] nums, int target) {
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
            } else if (target == nums[0]) {
                left = 0;
                break;
            } else if (target < nums[0] && nums[mid] >= nums[0]) {
                left = mid + 1;
            } else if (target < nums[0] && target < nums[mid]) {
                right = mid;
            } else if (target < nums[0] && target > nums[mid]) {
                left = mid + 1;
            } else if (target > nums[0] && nums[mid] < nums[0]) {
                right = mid;
            } else if (target > nums[0] && target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (nums[left] == target) {
            return left;
        }
        
        return -1;
    }
}
