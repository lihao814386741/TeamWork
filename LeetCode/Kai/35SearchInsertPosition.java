public class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i=0; i<nums.length; i++) {
            if(nums[i]<target) continue;
            else return i;
        }
        return nums.length;  //insert into the end of nums[]
    }
    
}