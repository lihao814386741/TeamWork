//log(n)
public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = new int[2];
        result[0] = findLeftMost(nums, nums.length, target);
        result[1] = findRightMost(nums, nums.length, target);
        return result;
    }
    
    public int findLeftMost(int[] nums, int len, int target) {
        int left = 0;
        int right = len-1;
        
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(nums[mid]<target) {
                left = mid+1;
            } else if(nums[mid]>target) {
                right = mid-1;
            } else {
                right = mid-1;  //can be combined with condition above
            }
        }
        if(left>=0 && left<=len-1 && nums[left]==target) return left;
        return -1;
    }
    
    public int findRightMost(int[] nums, int len, int target) {
        int left = 0;
        int right = len-1;
        
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(nums[mid]>target) {
                right = mid-1;
            } else if(nums[mid]<target) {
                left = mid+1;
            } else {
                left = mid+1;   //can be combined with condition above
            }
        }
        if(right>=0 && right<=len-1 && nums[right]==target) return right;
        return -1;
    }
    
}