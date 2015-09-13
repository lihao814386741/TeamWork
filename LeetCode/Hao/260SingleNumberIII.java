public class Solution {
    public int[] singleNumber(int[] nums) {
        int x, y;
        x = y = 0;
        
        for (int i = 0; i < nums.length; i ++) {
            x ^= nums[i];
        }
        
        int lowerbit = (x & (-x));
        
        y = x; 
        
        for (int i = 0; i < nums.length; i ++) {
            if ((lowerbit & nums[i]) != 0) {
                x ^= nums[i];
            }
        }
        
        y ^= x;
        
        return new int[]{x, y};
    }
}
