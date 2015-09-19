class Solution {
public:
    // negative n;
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        
        double result = 1;
        while (n > 0) {
            if (n & 0x01) {
                result *= x;
                cout << result << endl;
            }
            x *= x;
            n >>= 1;
        }
        return result;
    }
};
