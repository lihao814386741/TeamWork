public class Solution {
    public int findMin(int[] nums) {
        return binarySearch(nums, 0, nums.length-1);
    }
    
    public int binarySearch(int[] nums, int left, int right) {
        if(left==right) return nums[left];
        if(right-left == 1) return Math.min(nums[left], nums[right]);
        if(nums[left]<nums[right]) return nums[left];    //no rotation
        
        int mid = left + (right-left)/2;
        
        if(nums[mid]>nums[left]) {
            return binarySearch(nums, mid+1, right);
        } else {
            return binarySearch(nums, left, mid);
        }
    }
    
}