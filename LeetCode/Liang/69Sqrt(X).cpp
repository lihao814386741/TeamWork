ass Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        long long begin = 0, end = x; // Here must use long long.
        while (begin < end) {
            long long mid = begin + (end - begin) / 2;
            if (mid * mid < x) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        
        if (begin * begin > x) { // Probabely this is a better way to check binary search final result.
            return begin - 1;
        } else {
            return begin;
        }
    }
};
