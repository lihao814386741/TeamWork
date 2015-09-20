/**
 * Count 1s on each digit separately, then sum them up.
 *   - Pay attention to the boundries, especially 0 or 1 on each digit.
 **/ 
class Solution {
public:
    int countDigitOne(int n) {
        if (!n || n == 1) return n;
        int result = 0, x = n;
        long long tens = 1;
        while (tens <= n) {
            tens *= 10;
        }
        tens /= 10;
        while (tens) {
            if (x / tens > 1) {
                result += tens;
            } else if (x / tens == 1){
                result += x % tens + 1;
            }
            result += n / (tens * 10) * tens;
            x %= (tens);
            tens /= 10;
        }
        return result;
    }
};