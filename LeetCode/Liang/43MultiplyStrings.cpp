class Solution {
public:
    string multiply(string num1, string num2) {
        assert(num1.size() > 0 && num2.size() > 0);
        if ((num1.size() == 1 && num1.at(0) == '0') || (num2.size() == 1 && num2.at(0) == '0')) {
            // Use stoi() function will cause overflow;
            return "0";
        }
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int length = num1.size() + num2.size() - 1;
        string result(length, '0'); // Forget
        int carry = 0;
        for (int i = 0; i < length; ++i) {
            int tmpRes = carry;
            for (int j = 0; j <= i && j < num1.size(); ++j) {
                if (i - j < num2.size()) {
                    tmpRes += (num1.at(j) - '0') * (num2.at(i - j) - '0');   
                }
            }
            carry = tmpRes / 10;
            tmpRes %= 10;
            result.at(i) = char(tmpRes + '0');
        }
        
        if (carry > 0 ) {
            result.push_back((char)(carry + '0'));
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
