/**
 * Be careful with the space.
 **/ 
class Solution {
public:
    void helper(string& result, int num) {
        if (num >= 100) {
            result += lessThan20[num / 100] + " Hundred";
            num %= 100;
            if (num) {
                result += " ";
            }
        }
        if (num >= 20) {
            result += lessThan100[num / 10];
            num %= 10;
            if (num) {
                result += " ";
            }
        }
        if (num) {
            result += lessThan20[num];
        }
    }
    string numberToWords(int num) {
        if (!num) return "Zero";
        string result[4] = {"", "", "", ""};
        const string words[4] = {"", " Thousand", " Million", " Billion"};
        for (int i = 0; num && i < 4; i++) {
            if (num % 1000) {
                if (num / 1000) {
                    result[i] += " ";
                }
                helper(result[i], num % 1000);
                result[i] += words[i];
            }
            num /= 1000;
        }
        return result[3] + result[2] + result[1] + result[0];
    }
private:
    const string lessThan20[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                   "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string lessThan100[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};