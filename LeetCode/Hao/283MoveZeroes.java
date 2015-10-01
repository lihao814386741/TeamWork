public class Solution {
    public void moveZeroes(int[] nums) {
        
        int last = 0;
        
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] != 0) {
                nums[last] = nums[i];
                last ++;
            }
        }
        for (; last < nums.length; last ++) {
            nums[last] = 0;
        }
        
        
    }
}
