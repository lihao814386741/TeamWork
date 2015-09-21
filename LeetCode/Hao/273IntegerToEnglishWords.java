public class Solution {
    String[] ones = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
    };
    String[] teens = {
        "",  "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
        "Eighteen", "Nineteen"
    };
    String[] ties = {
        "", "Ten", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
    
    private String getNumberLessThan1000(int m){
        String result = "";
        int h = m / 100;
        int t = m / 10 % 10;
        if (h != 0) {
            result += ones[h] + " Hundred ";
        }
        if (t > 1) {
            result += ties[t] + " ";
            if (m % 10 != 0) {
                result += ones[m % 10] + " ";
            }
        } else if (t == 1) {
            if (m % 10 != 0) {
                result += teens[m % 10] + " ";
            } else {
                result += "Ten ";
            }
        } else {
            if (m % 10 != 0) {
                result += ones[m % 10] + " ";
            }
        }
        
        return result;
    }
    private String addNumber(int num, int shift, String output) {
        int d = num / shift;
        d %= 1000;
        String result = "";
        if(d != 0) {
            result += getNumberLessThan1000(d) + output +" ";
        }
        
        return result;
    }
    
    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        String result = "";
        
        result += addNumber(num, 1000000000, "Billion");
        result += addNumber(num, 1000000, "Million");
        result += addNumber(num, 1000, "Thousand");
        result += getNumberLessThan1000(num % 1000);
        
        return result.trim();
    }
}
