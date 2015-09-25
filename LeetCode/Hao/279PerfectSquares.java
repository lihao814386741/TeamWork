public class Solution {
    public int numSquares(int n) {
        int[] d = new int[n+1];
        d[1] = 1;
        
        for (int i = 1; i * i <= n; i ++) {
            d[i * i] = 1;
        }
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j * j <= i; j ++) {
                int ans = d[i - j * j] + 1;
                d[i] = (d[i] == 0) ? ans : Math.min(ans, d[i]);
            }
        }
        
        return d[n];
    }
}
