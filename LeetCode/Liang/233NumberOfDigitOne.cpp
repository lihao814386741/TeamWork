/**
 * Special thanks to:
 * Hao and https://leetcode.com/discuss/46366/ac-short-java-solution
 **/
class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) return 0;
        if (n >= 1 && n < 10) return 1;
        
        int result = 0;
        int right = n;
        for (int i = 1; i <= n; i *= 10) {
            int current = right % 10;
            right /= 10;
            if (current > 1) {
                result += (right + 1) * i;
            } else if (current == 1){
                // Left part of current position i;
                int left = n % i;
                result += right * i + left + 1;
            } else {
                result += right * i;
            }
        }
        return result;
    }
};
