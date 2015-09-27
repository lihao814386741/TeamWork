public class Solution {
    public int removeDuplicates(int[] nums) {
        int p1 = 0;
        int p2 = 1;
        int dupCount = 0;
        
        while(p2<nums.length) {
            if(nums[p1]==nums[p2]) {
                dupCount++;
                p2++;
            } else {
                p1++;
                nums[p1] = nums[p2];
                p2++;
            }
        }
        return nums.length-dupCount;
    }
    
}