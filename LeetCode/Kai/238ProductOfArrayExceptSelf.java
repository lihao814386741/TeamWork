public class Solution {
    public int[] productExceptSelf(int[] nums) {
        int product = 1;
        int[] result = new int[nums.length];
        
        int countZero = 0;
        int indexOfZero = 0;
        for(int i=0; i<nums.length; i++) {
            if(nums[i]==0) {
                countZero++;
                indexOfZero = i;
                continue;
            }
            product *= nums[i];
        }
        
        if(countZero==1) {      //if one 0, all other output[i]==0 except for this one
            result[indexOfZero] = product;
            return result;
        }
        if(countZero>=2) return result;  //if more than one 0, all output[i]==0
        
        for(int i=0; i<nums.length; i++) {
            result[i] = product/nums[i];
        }
        return result;
    }
    
}