/**
 * A new method to iterate ordered map. Use reverse_iterator, rbegin, rend.
 **/
static map<int, string> dict = {
    {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
    {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
}; // Do not forget ";".

class Solution {
public:
    string intToRoman(int num) {
        if (num == 0) return "";
        
        string result = "";
        for (auto ritr = dict.rbegin(); ritr != dict.rend(); ++ritr) {
            while (num >= ritr->first) {
                 num -= ritr->first;
                 result += ritr->second;
            }
        }
        return result;
    }
};
