public class Solution {
    public int maxProduct(int[] nums) {
        int[] dpMax = new int[nums.length];
        int[] dpMin = new int[nums.length];
        
        dpMax[0] = nums[0];    //base
        dpMin[0] = nums[0];
        int maxProduct = nums[0];
        
        for(int i=1; i<nums.length; i++) {
            dpMax[i] = Math.max(Math.max(dpMax[i-1]*nums[i], nums[i]), dpMin[i-1]*nums[i]);
            dpMin[i] = Math.min(Math.min(dpMin[i-1]*nums[i], nums[i]), dpMax[i-1]*nums[i]);
            maxProduct = Math.max(maxProduct, dpMax[i]);
        }
        
        return maxProduct;
    }
    
}