/**
 * Just add the carry to the next digit, finally just check the highest
 * digit.
 **/ 
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        if (!l1 || !l2 || num1 == "0" || num2 == "0") return "0";
        
        string result = "";
        vector<int> digits(l1 + l2, 0);
        for (int i = l1 - 1; i >= 0; i--) {
            int a = num1.at(i) - '0';
            int pos = l1 - i - 1;
            for (int j = l2 - 1; j >= 0; j--, pos++) {
                int b = num2.at(j) - '0';
                int temp = a * b + digits.at(pos);
                digits.at(pos) = temp % 10;
                digits.at(pos + 1) += temp / 10;
            }
        }
        
        if (digits.at(l1 + l2 - 1)) {
            result += to_string(digits.at(l1 + l2 - 1));
        }
        for (int i = digits.size() - 2; i >= 0; i--) {
            result += to_string(digits.at(i));
        }
        return result;
    }
};