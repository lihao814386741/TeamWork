public class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==1) return true;
        
        int[] dp = new int[nums.length];
        dp[0] = nums[0];       //base
        
        for(int i=1; i<nums.length; i++) {
            if(dp[i-1]-1<0) return false;     //reach 0. Can't jump
            dp[i] = Math.max(dp[i-1]-1, nums[i]);   //keep track of the most remaining steps for i
        }
        
        return true;
    }
    
}