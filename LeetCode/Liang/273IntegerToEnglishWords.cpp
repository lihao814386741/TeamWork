static unordered_map<int, string> dict = {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, 
    {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
    {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
    {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
    {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
    {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
};

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return dict[num];
        }
        
        string result = "";
        result += numberUnderThousandHelper(num / 1000000000, " Billion");
        
        num %= 1000000000;
        result += numberUnderThousandHelper(num / 1000000, " Million");
        
        num %= 1000000;
        result += numberUnderThousandHelper(num / 1000, " Thousand");
        
        num %= 1000;
        result += numberUnderThousandHelper(num, "");
        
        // Eliminate front whitespace
        if (result[0] == ' ') {
            result = result.substr(1);   
        }
        return result;
    }
    
private:
    string numberUnderThousandHelper(int num, string suffix) {
        if (num == 0) return "";
        
        string result = "";
        if (num / 100) {
            result += " " + dict[num / 100];
            result += " Hundred";
        }
        
        num %= 100;
        if (num / 10 > 1) {
            result += " " + dict[(int)(num / 10) * 10];
            num %= 10;
        }
                
        if (num) {
            result += " " + dict[num];
        }
        
        return result + suffix;
    }
};
