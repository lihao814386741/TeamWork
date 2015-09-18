public class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        for(int i=1; i*i<=n; i++) dp[i*i] = 1;   //base
        
        for(int i=1; i<=n; i++) {
            for(int j=1; i+j*j<=n; j++) {
                dp[i+j*j] = Math.min(dp[i+j*j], dp[i]+1);
            }
        }
        
        return dp[n];
        
    }
    
}