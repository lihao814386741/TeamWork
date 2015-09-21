//1. 0 != 1.0
//2. Pow(x, -n) = 1/Pow(x, n)
//3. -INT_MIN = INT_MAX + 1
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0) {
            if (n == INT_MIN) {
                return 1 / (myPow(x,INT_MAX) * x);
            } 
            return 1 / myPow(x, -n);
        }
        double half = myPow(x, n >> 1);
        if (n % 2) {
            return half * half * x;
        } else {
            return half * half;
        }
    }
};