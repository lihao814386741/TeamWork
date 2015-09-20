/**
 * 1. Divided by zero, return INT_MAX
 * 2. INT_MIN / (-1) = INT_MAX
 **/ 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        
        long long a = dividend, b = divisor, result = 0, count = 1;
        a = abs(a);
        b = abs(b);
        int flag = 0;
        if (dividend < 0 ^ divisor < 0) flag = 1;
        while (a >= b << 1) {
            count = count << 1;
            b = b << 1;
        }
        while (count) {
            if (a >= b) {
                result += count;
                a -= b;
            }
            b = b >> 1;
            count = count >> 1;
        }
        
        if (flag) return -result;
        return result;
    }
};