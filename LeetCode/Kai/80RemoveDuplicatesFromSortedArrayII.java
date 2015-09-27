public class Solution {
    public int removeDuplicates(int[] nums) {
        int p1 = 0;
        int p2 = 1;
        int dupCount = 0;
        int count = 1;
        
        while(p2<nums.length) {
            if(nums[p1]==nums[p2]) {
                if(count == 1) {
                    p1++;
                    nums[p1] = nums[p2];
                } else {
                    dupCount++;
                }
                count++;
                p2++;
            } else {
                p1++;
                nums[p1] = nums[p2];
                p2++;
                count = 1;
            }
        }
        return nums.length-dupCount;
    }
    
}