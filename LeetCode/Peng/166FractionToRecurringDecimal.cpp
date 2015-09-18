//abs(INT_MIN) will overflow, use long instead
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if (!denominator) return result;
        
        if (numerator && (numerator < 0) ^ (denominator < 0)) {
            result.push_back('-');
        }
        long long num = numerator;
        num = abs(num);
        long long den = denominator;
        den = abs(den);
        long long remaining = num % den;
        result += to_string(num / den);
        int i = result.size();
        int point = 1;
        unordered_map<long long, int> positions;
        while (remaining) {
            if (!positions.count(remaining)) {
                if (remaining < den) {
                    if (point) {
                        point = 0;
                        result += ".";
                        i++;
                    }
                    positions[remaining] = i++;
                    remaining *= 10;
                }
                result += to_string(remaining / den);
                remaining %= den;
            } else {
                result.insert(result.begin() + positions.at(remaining), '(');
                result += ")";
                break;
            }
        }
        return result;
    }
};