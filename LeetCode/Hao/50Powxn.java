public class Solution {
    public double myPow(double x, int n) {
        double sum = 1;
        double cur = x; 
        
        if (n < 0) {
            n = -n;
            cur = 1 / x;
        } else if (n == 0) {
            return 1;
        }
        
        for (long index = 1; index <= n; index = (index << 1)) {
            if ((index & n) != 0) {
                sum *= cur;
            }
            
            cur *= cur;
        }
        
        return sum; 
    }
}
