//1. Pay attention to negative
//2. Carefully deal with overflow (long long, INT_MIN == INT_MAX+1)
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        int begin = 0;
        int end = x;
        while (begin < end) {
            long long mid = begin + (end - begin) / 2;
            long long temp = mid * mid;
            if (temp > x) {
                end = mid - 1;
            } else if (temp < x) {
                begin = mid + 1;
            } else {
                return mid;
            }
        }
        if (begin * begin > x) begin--;
        return begin;
    }
};