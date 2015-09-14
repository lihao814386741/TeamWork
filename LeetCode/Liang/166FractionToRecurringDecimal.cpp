class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        assert(denominator != 0);
        if (numerator == 0) {
            return "0";
        }
        
        // sign
        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        
        long long newNumerator = abs((long long)numerator);
        long long newDenominator = abs((long long)denominator);
        
        result += to_string(newNumerator / newDenominator);
        newNumerator %= newDenominator;
        if (newNumerator == 0) {
            return result;
        } else {
            result += ".";
        }
        
        unordered_map<int, int> hash;
        
        while (newNumerator) {
            if (hash.find(newNumerator) != hash.end()) {
                result.insert(hash[newNumerator], "(");
                result += ")";
                return result;
            }
            
            hash[newNumerator] = result.size();
            newNumerator *= 10;
            result += to_string(newNumerator / newDenominator);
            newNumerator = newNumerator % newDenominator;
        }
        return result;
    }
};
