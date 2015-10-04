//Similar to dp
public class Solution {
    public int maxSubArray(int[] num) {
        int localMax = 0;
        int maxSum = Integer.MIN_VALUE;
        for(int i=0; i<num.length; i++) {
            localMax = Math.max(localMax+num[i], num[i]);
            maxSum = Math.max(maxSum, localMax);
        }
        return maxSum;
    }
    
}


//DP
public class Solution {
    public int maxSubArray(int[] num) {
        int[] dp = new int[num.length];
        dp[0] = num[0];    //base
        int maxSum = dp[0];
        
        for(int i=1; i<num.length; i++) {
            dp[i] = Math.max(dp[i-1]+num[i], num[i]);
            maxSum = Math.max(dp[i], maxSum);
        }
        return maxSum;
    }
}