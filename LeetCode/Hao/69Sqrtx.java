public class Solution {
    public int mySqrt(int x) {
        int left = 0;
        int right = x;
        
        while (left <= right) {
            if (left == right) {
                break;
            }
            
            int mid = (left + right) / 2;
            
            if ((long)mid * mid == x) {
                return mid;
            } else if ((long)mid * mid < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if ((long)left * left > right) {
            return left - 1;
        } else {
            return left;
        }
        
    }
}
