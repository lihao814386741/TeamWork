public class Solution {
    public int divide(int dividend, int divisor) {
        int sign = 1;
        long tmp = dividend >= 0 ? (long)dividend : (long)-1 * dividend;
        long tmpdivisor = divisor >= 0 ? (long)divisor : (long)-1 * divisor; 

        if (dividend < 0) {
            sign *= -1;
        } 
        if (divisor < 0) {
            sign *= -1;
        }
        
        if (tmpdivisor == 0) {
            return Integer.MAX_VALUE;
        } else if (tmpdivisor > tmp) {
            return 0; 
        }
        long originaldivisor = tmpdivisor;

        for (long i = originaldivisor; i <= tmp; i <<= 1) {
            tmpdivisor = Math.max(i, tmpdivisor);
        }
        
        long result = 0;
        
        while (tmpdivisor >= originaldivisor) {
            if (tmp >= tmpdivisor) {
                tmp -= tmpdivisor;
                tmpdivisor >>= 1;
                result <<= 1;
                result += 1;
            }  else {
                tmpdivisor >>= 1;
                result <<= 1;
            }
        }
        result = sign * result;
        return result > (long)Integer.MAX_VALUE? Integer.MAX_VALUE : Long.valueOf(result).intValue();
    }
}
