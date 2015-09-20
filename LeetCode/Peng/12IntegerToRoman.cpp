class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> dict = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, 
                                           {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        int candidates[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";
        for (int i = 0; i < 13; i++) {
            int scale = candidates[i];
            while (num >= scale) {
                result += dict.at(scale);
                num -= scale;
            }
        }
        return result;
    }
};