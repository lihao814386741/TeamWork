public class Solution {
    String[] ones = {
        "", "I","II","III","IV","V","VI","VII","VIII","IX",
    };
    String[] tens = {
        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"  
    };
    String[] hundreds = {
        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
    };
    String[] thouands = {
        "", "M", "MM", "MMM", "MMMM"
    };
    public String intToRoman(int num) {
        String result = "";
        
        
        result += thouands[num/1000] + hundreds[num / 100 % 10] + tens[num / 10 % 10] + ones[num % 10];
        
        return result;
    }
}
