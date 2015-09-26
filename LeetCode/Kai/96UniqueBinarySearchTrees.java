public class Solution {
    public int numTrees(int n) {
        int dp[] = new int[n+1];
        
        dp[0] = 1;    //base
        dp[1] = 1;
        
        for(int i=2; i<=n; i++) {
            int k = i-1;
            for(int j=0; j<=k; j++) {
                dp[i] += dp[j] * dp[k-j];
            }
        }
        
        return dp[n];
    }
    
}