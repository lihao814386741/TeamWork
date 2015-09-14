public class Solution {
    public int singleNumber(int[] nums) {
        int[] b = new int[32];
        
        for (int i = 0; i < nums.length; i ++) {
            int bit = 1;
            for (int j = 0; j < 32; j ++) {
                if ((bit & nums[i]) != 0) {
                    b[j] += 1;
                }
                bit <<= 1;
            }
        }
        
        int result = 0;
        int bit = 1;
        for (int i = 0; i < 32; i ++) {
            if (b[i] % 3 != 0) {
                result += bit;
            }
            
            bit <<= 1;
        }
        
        return result;
    }
}
