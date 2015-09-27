public class Solution {
    public boolean search(int[] nums, int target) {
        return binarySearch(nums, 0, nums.length-1, target);
    }
    
    public boolean binarySearch(int nums[], int left, int right, int target) {
        if(left>right) return false;
        
        int mid = left + (right-left)/2;   //better way, not mid = (left+right)/2, may cause overflow
        if(nums[mid]==target) return true;
        
        if(nums[left]<nums[mid]) {
            if(nums[left]<=target && target<nums[mid]) {
                return binarySearch(nums, left, mid-1, target);
            } else {
                return binarySearch(nums, mid+1, right, target);
            }
        } else if(nums[left]>nums[mid]) {
            if(nums[mid]<target && target<=nums[right]) {
                return binarySearch(nums, mid+1, right, target);
            } else {
                return binarySearch(nums, left, mid-1, target);
            }
        } else {
            return binarySearch(nums, left+1, right, target);   //skip duplicate when nums[left]==nums[mid]
        }
    }
    
}